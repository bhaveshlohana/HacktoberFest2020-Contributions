# -*- coding: utf-8 -*-

import os

import numpy as np

import xeno


def get_data():
    corpus_path = os.path.join(os.path.dirname(__file__), 'data/lm/tiny_shakespeare.txt')

    raw_text = open(corpus_path, 'r').read()
    chars = list(set(raw_text))
    data_size, vocab_size = len(raw_text), len(chars)
    print("data has %s charactres, % unique." % (data_size, vocab_size))
    char_to_index = {ch: i for i, ch in enumerate(chars)}
    index_to_char = {i: ch for i, ch in enumerate(chars)}

    time_steps, batch_size = 30, 40
    length = batch_size * 20
    text_pointers = np.random.randint(data_size - time_steps - 1, size=length)
    batch_in = np.zeros([length, time_steps, vocab_size])
    batch_out = np.zeros([length, vocab_size], dtype=np.uint8)
    for i in range(length):
        b_ = [char_to_index[c] for c in raw_text[text_pointers[i]:text_pointers[i] + time_steps + 1]]
        batch_in[i, range(time_steps), b_[:-1]] = 1
        batch_out[i, b_[-1]] = 1

    return batch_size, vocab_size, time_steps, batch_in, batch_out


def main1(max_iter):
    batch_size, vocab_size, time_steps, batch_in, batch_out = get_data()

    print("Building model ...")
    net = xeno.Model()
    net.add(xeno.layers.BatchLSTM(n_out=300, n_in=vocab_size, return_sequence=True,
                                  nb_batch=batch_size, nb_seq=time_steps))
    net.add(xeno.layers.MeanPooling(pool_size=(time_steps, 1)))
    net.add(xeno.layers.Flatten())
    net.add(xeno.layers.Softmax(n_out=vocab_size))
    net.compile(loss=xeno.objectives.SCCE(), optimizer=xeno.optimizers.SGD(lr=0.00001, clip=5))

    print("Train model ...")
    net.fit(batch_in, batch_out, max_iter=max_iter, batch_size=batch_size)


def main2(max_iter):
    batch_size, vocab_size, time_steps, batch_in, batch_out = get_data()

    print("Building model ...")
    net = xeno.Model()
    net.add(xeno.layers.BatchLSTM(n_out=300, n_in=vocab_size, return_sequence=False,
                                  nb_batch=batch_size, nb_seq=time_steps))
    # net.add(xeno.layers.MeanPooling(pool_size=(time_steps, 1)))
    # net.add(xeno.layers.Flatten())
    net.add(xeno.layers.Softmax(n_out=vocab_size))
    net.compile(loss=xeno.objectives.SCCE(), optimizer=xeno.optimizers.SGD(lr=0.00001, clip=5))

    print("Train model ...")
    net.fit(batch_in, batch_out, max_iter=max_iter, batch_size=batch_size)


if __name__ == '__main__':
    main1(100)
