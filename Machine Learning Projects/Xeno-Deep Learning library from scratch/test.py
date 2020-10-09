import numpy as np
import xeno

try:
    from sklearn.datasets import load_digits
except:
    print("your sklearn library needs to be install with whl of numpy+MKL :(\n")

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