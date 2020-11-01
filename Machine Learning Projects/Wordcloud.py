#!/usr/bin/env python
"""jupyter-wordcloud
====================
Generate wordcloud from Jupyter notebooks.
"""
from argparse import ArgumentParser
from nbconvert import RSTExporter
from os import path, remove
import re
from wordcloud import WordCloud, STOPWORDS
import matplotlib.pyplot as plt
import numpy as np


parser = ArgumentParser(
    prog='jupyter-wordcloud',
    description='jupyter notebooks > RST > wordcloud as image')
parser.add_argument('path_ipynb', help='input Jupyter notebook')
parser.add_argument('-w', '--width', help='width in pixels', default=400,
        type=int)
parser.add_argument('-e', '--height', help='height in pixels', default=200,
        type=int)
parser.add_argument('-x', '--max-words', help='max. words', default=200,
        type=int)
parser.add_argument('-o', '--output', help='output image path', default=None)
parser.add_argument(
        '-r', '--keep-rstdir', help='keep RST directives',
        action='store_true')
parser.add_argument(
        '-k', '--keep-html', help='keep HTML tags',
        action='store_true')
parser.add_argument(
        '-v', '--verbose', help='display converted text',
        action='store_true')


def clean_rstdir(raw_rst):
    """Clean up RST directive blocks."""

    raw_rst = raw_rst.splitlines()
    clean_rst = []
    inside_rst_dir_block = False
    for line in raw_rst:
        if line.startswith('.. '):
            inside_rst_dir_block = True
            continue
        else:
            clean_rst.append(line)

        if inside_rst_dir_block and (
                line.startswith('    ') or line == ''):
            continue
        else:
            inside_rst_dir_block = False

    return '\n'.join(clean_rst)


def clean_html(raw_html):
    cleanr = re.compile('<.*?>')
    cleantext = re.sub(cleanr, '', raw_html)
    return cleantext



def convert_to_rst(notebook, cache=True):
    notebook_mtime = path.getmtime(notebook)
    path_dir = path.dirname(notebook)
    cache_file = path.join(path_dir, '.{}_{}'.format(
        notebook_mtime, path.basename(notebook)))

    if path.exists(cache_file):
        print('Reading from cache: ', cache_file)
        with open(cache_file) as f:
            body = f.read()
        if body == '':
            remove(cache_file)
            return convert_to_rst(notebook, cache)
    else:
        # Instantiate it
        rst_exporter = RSTExporter()
        # Convert the notebook to RST format
        (body, resources) = rst_exporter.from_filename(notebook)

        print('Writing to cache: ', cache_file)
        with open(cache_file, 'w') as f:
            f.write(body)
    return body


def main(args=None):
    if args is None:
        args = parser.parse_args()

    notebook = args.path_ipynb
    body = convert_to_rst(notebook)
    if not args.keep_rstdir:
        body = clean_rstdir(body)

    if not args.keep_html:
        body = clean_html(body)

    if args.verbose:
        print(body)

    # TODO: unnecessary or remove hardcoding
    blacklist = {
        'src', 'fig', 'raw', 'html', 'latex', 'bf', 'img', 'div', 'math', 'png',
        'alt', 'align', 'green', 'Ding', 'link', 'nbsp', 'cdot', 'nabla', 'frac',
        'partial', 'eta', 'style', 'width', 'right', 'left', 'center', 'Result',
        'drawing'}
    stopwords = set(STOPWORDS).union(blacklist)

    wordcloud = WordCloud(
        background_color="white", stopwords=stopwords, width=args.width,
        height=args.height, max_words=args.max_words, margin=0)
    wordcloud.generate(body)

    dpi = 300
    plt.rc('figure', dpi=dpi)
    figsize = np.array([args.width, args.height]) / dpi ** 0.5

    fig, ax = plt.subplots(figsize=figsize)
    ax.imshow(wordcloud, interpolation='bilinear')
    plt.axis('off')
    plt.tight_layout()
    if args.output is None:
        plt.show()
    else:
        output = path.splitext(path.basename(notebook))[0] + '_wordcloud.png'
        output = path.join(args.output, output)
        print('Saving to', output)
        fig.savefig(output)


if __name__ == '__main__':
    main()
