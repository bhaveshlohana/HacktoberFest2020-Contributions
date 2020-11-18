 
    
Xeno:Deep learning library from Scratch.
============

Scalable deep learning library built from scratch. Purely based on NumPy.

*Currently in build phase*

Descriptions
============

``Xeno`` is:

1. Based on pure Numpy/Python.
2. Just a midnight curiosity forming real shape.
3. Supports linear stacking of layers.

Features
============
``Xeno`` contains following dee learning features, currently:

* Activations
    * Sigmoid
    * Tanh
    * ReLU
    * Linear
    * Softmax
    * Elliot
    * SymmetricElliot
    * SoftPlus
    * SoftSign     
* Initializations
    * Zero
    * One
    * Uniform
    * Normal
    * LecunUniform
    * GlorotUniform
    * GlorotNormal
    * HeNormal
    * HeUniform
    * Orthogonal
* Layers
    * Linear
    * Dense
    * Convolution
    * Softmax
    * Dropout
    * Embedding
    * BatchNormal
    * MeanPooling
    * MaxPooling
    * SimpleRNN
    * GRU
    * LSTM
    * Flatten
    * DimShuffle 
* Objectives
    * Objectives
    * MeanSquaredError
    * HellingerDistance
    * BinaryCrossEntropy
    * SoftmaxCategoricalCrossEntropy 
* Optimizers
    * SGD
    * Momentum
    * NesterovMomentum
    * Adagrad
    * RMSprop
    * Adadelta
    * Adam
    * Adamax 



One simple code example: 

.. image:: https://colab.research.google.com/assets/colab-badge.svg
   :target: https://colab.research.google.com/github/manncodes/xeno/blob/master/XenoDemoInColab.ipynb

.. code-block:: python

    import numpy as np
    from sklearn.datasets import load_digits
    import xeno

    # prepare
    xeno.utils.random.set_seed(1234)

    # data
    digits = load_digits()
    X_train = digits.data
    X_train /= np.max(X_train)
    Y_train = digits.target
    n_classes = np.unique(Y_train).size

    # model
    model = xeno.model.Model()
    model.add(xeno.layers.Dense(n_out=500, n_in=64, activation=xeno.activations.ReLU()))
    model.add(xeno.layers.Dense(n_out=n_classes, activation=xeno.activations.Softmax()))
    model.compile(loss=xeno.objectives.SCCE(), optimizer=xeno.optimizers.SGD(lr=0.005))

    # train
    model.fit(X_train, xeno.utils.data.one_hot(Y_train), max_iter=150, validation_split=0.1) 
    


Another example of an LSTM sentence classifier in xeno: 

.. image:: https://colab.research.google.com/assets/colab-badge.svg
   :target: https://colab.research.google.com/github/manncodes/xeno/blob/master/XenoDemoInColab.ipynb

.. code-block:: python

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
