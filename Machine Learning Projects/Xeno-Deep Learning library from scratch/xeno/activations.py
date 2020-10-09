# -*- coding: utf-8 -*-

import copy

import numpy as np

from xeno.utils.random import get_dtype

# activation-start
class Activation(object):
    def __init__(self):
        self.last_forward = None

    def forward(self, input):
        raise NotImplementedError

    def derivative(self, input=None):
        raise NotImplementedError

    def __str__(self):
        return self.__class__.__name__



class Sigmoid(Activation):

    def __init__(self):
        super(Sigmoid, self).__init__()

    def forward(self, input, *args, **kwargs):
        self.last_forward = 1.0 / (1.0 + np.exp(-input))
        return self.last_forward

    def derivative(self, input=None):
        last_forward = self.forward(input) if input else self.last_forward
        return np.multiply(last_forward, 1 - last_forward)



class Tanh(Activation):
    def __init__(self):
        super(Tanh, self).__init__()

    def forward(self, input):
        self.last_forward = np.tanh(input)
        return self.last_forward

    def derivative(self, input=None):
        last_forward = self.forward(input) if input else self.last_forward
        return 1 - np.power(last_forward, 2)


class ReLU(Activation):
    def __init__(self):
        super(ReLU, self).__init__()

    def forward(self, input):
        self.last_forward = input
        return np.maximum(0.0, input)

    def derivative(self, input=None):
        last_forward = input if input else self.last_forward
        res = np.zeros(last_forward.shape, dtype=get_dtype())
        res[last_forward > 0] = 1.
        return res



class Linear(Activation):

    def __init__(self):
        super(Linear, self).__init__()

    def forward(self, input):
        self.last_forward = input
        return input

    def derivative(self, input=None):
        last_forward = input if input else self.last_forward
        return np.ones(last_forward.shape, dtype=get_dtype())




class Softmax(Activation):
    

    def __init__(self):
        super(Softmax, self).__init__()

    def forward(self, input):
        assert np.ndim(input) == 2
        self.last_forward = input
        x = input - np.max(input, axis=1, keepdims=True)
        exp_x = np.exp(x)
        s = exp_x / np.sum(exp_x, axis=1, keepdims=True)
        return s

    def derivative(self, input=None):
        last_forward = input if input else self.last_forward
        return np.ones(last_forward.shape, dtype=get_dtype())



class Elliot(Activation):
    def __init__(self, steepness=1):
        super(Elliot, self).__init__()

        self.steepness = steepness

    def forward(self, input):
        self.last_forward = 1 + np.abs(input * self.steepness)
        return 0.5 * self.steepness * input / self.last_forward + 0.5

    def derivative(self, input=None):
        last_forward = 1 + np.abs(input * self.steepness) if input else self.last_forward
        return 0.5 * self.steepness / np.power(last_forward, 2)





class SymmetricElliot(Activation):

    def __init__(self, steepness=1):
        super(SymmetricElliot, self).__init__()
        self.steepness = steepness

    def forward(self, input):
        self.last_forward = 1 + np.abs(input * self.steepness)
        return input * self.steepness / self.last_forward

    def derivative(self, input=None):
        last_forward = 1 + np.abs(input * self.steepness) if input else self.last_forward
        return self.steepness / np.power(last_forward, 2)



class SoftPlus(Activation):

    def __init__(self):
        super(SoftPlus, self).__init__()

    def forward(self, input):
        self.last_forward = np.exp(input)
        return np.log(1 + self.last_forward)

    def derivative(self, input=None):
        last_forward = np.exp(input) if input else self.last_forward
        return last_forward / (1 + last_forward)



class SoftSign(Activation):

    def __init__(self):
        super(SoftSign, self).__init__()

    def forward(self, input):
        self.last_forward = np.abs(input) + 1
        return input / self.last_forward

    def derivative(self, input=None):
        last_forward = np.abs(input) + 1 if input else self.last_forward
        return 1. / np.power(last_forward, 2)



def get(activation):
    if activation.__class__.__name__ == 'str':
        if activation in ['sigmoid', 'Sigmoid']:
            return Sigmoid()
        if activation in ['tan', 'tanh', 'Tanh']:
            return Tanh()
        if activation in ['relu', 'ReLU', 'RELU']:
            return ReLU()
        if activation in ['linear', 'Linear']:
            return Linear()
        if activation in ['softmax', 'Softmax']:
            return Softmax()
        if activation in ['elliot', 'Elliot']:
            return Elliot()
        if activation in ['symmetric_elliot', 'SymmetricElliot']:
            return SymmetricElliot()
        if activation in ['SoftPlus', 'soft_plus', 'softplus']:
            return SoftPlus()
        if activation in ['SoftSign', 'softsign', 'soft_sign']:
            return SoftSign()
        raise ValueError('Unknown activation name: {}.'.format(activation))

    elif isinstance(activation, Activation):
        return copy.deepcopy(activation)

    else:
        raise ValueError("Unknown type: {}.".format(activation.__class__.__name__))