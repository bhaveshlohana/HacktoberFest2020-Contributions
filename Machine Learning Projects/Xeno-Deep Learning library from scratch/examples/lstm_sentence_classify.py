# -*- coding: utf-8 -*-

import os

import numpy as np

import xeno


def prepare_data(nb_seq=20):
    all_xs = []
    all_ys = []
    all_words = set()
    all_labels = set()

    # get all words and labels
    with open(os.path.join(os.path.dirname(__file__), 'data/trec/TREC_10.label')) as fin:
        for line in fin:
            words = line.strip().split()
            y = words[0].split(':')[0]
            xs = words[1:]
            all_xs.append(xs)
            all_ys.append(y)

            for word in words:
                all_words.add(word)
            all_labels.add(y)

    word2idx = {w: i for i, w in enumerate(sorted(all_words))}
    label2idx = {label: i for i, label in enumerate(sorted(all_labels))}

    # get index words and labels
    all_idx_xs = []
    for sen in all_xs:
        idx_x = [word2idx[word] for word in sen[:nb_seq]]
        idx_x = [0] * (nb_seq - len(idx_x)) + idx_x
        all_idx_xs.append(idx_x)
    all_idx_xs = np.array(all_idx_xs, dtype='int32')

    all_idx_ys = xeno.utils.data.one_hot(
        np.array([label2idx[label] for label in all_ys], dtype='int32'))

    return all_idx_xs, all_idx_ys, len(word2idx), len(label2idx)


def main(max_iter):
    nb_batch = 30
    nb_seq = 20

    xs, ys, x_size, y_size = prepare_data(nb_seq)

    net = xeno.Model()
    net.add(xeno.layers.Embedding(nb_batch=nb_batch, nb_seq=nb_seq,
                                  n_out=200, input_size=x_size,
                                  static=True))
    net.add(xeno.layers.BatchLSTM(n_out=400, return_sequence=True))
    net.add(xeno.layers.BatchLSTM(n_out=200, return_sequence=True))
    net.add(xeno.layers.MeanPooling((nb_seq, 1)))
    net.add(xeno.layers.Flatten())
    net.add(xeno.layers.Softmax(n_out=y_size))
    net.compile(loss='scce', optimizer=xeno.optimizers.SGD(lr=0.005))
    net.fit(xs, ys, batch_size=nb_batch, validation_split=0.1, max_iter=max_iter)


def main2(max_iter):
    nb_batch = 30
    nb_seq = 20

    xs, ys, x_size, y_size = prepare_data(nb_seq)

    net = xeno.Model()
    net.add(xeno.layers.Embedding(nb_batch=nb_batch, nb_seq=nb_seq,
                                  n_out=200, input_size=x_size,
                                  static=False))
    net.add(xeno.layers.BatchLSTM(n_out=400, return_sequence=True))
    net.add(xeno.layers.BatchLSTM(n_out=200, return_sequence=True))
    net.add(xeno.layers.MeanPooling((nb_seq, 1)))
    net.add(xeno.layers.Flatten())
    net.add(xeno.layers.Softmax(n_out=y_size))
    net.compile(loss='scce', optimizer=xeno.optimizers.RMSprop())
    net.fit(xs, ys, batch_size=nb_batch, validation_split=0.1, max_iter=max_iter)


if __name__ == '__main__':
    main2(100)
