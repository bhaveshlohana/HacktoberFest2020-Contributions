# -*- coding: utf-8 -*-

import copy
import numpy as np


class Objective(object):

    def forward(self, outputs, targets):
        
        raise NotImplementedError()

    def backward(self, outputs, targets):
        raise NotImplementedError()

    def __str__(self):
        return self.__class__.__name__


class MeanSquaredError(Objective):

    def forward(self, outputs, targets):
        return 0.5 * np.mean(np.sum(np.power(outputs - targets, 2), axis=1))

    def backward(self, outputs, targets):
        return outputs - targets


MSE = MeanSquaredError


class HellingerDistance(Objective):

    def forward(self, outputs, targets):
        root_difference = np.sqrt(outputs) - np.sqrt(targets)
        return np.mean(np.sum(np.power(root_difference, 2), axis=1) / np.sqrt(2))

    def backward(self, outputs, targets):
        root_difference = np.sqrt(outputs) - np.sqrt(targets)
        return root_difference / (np.sqrt(2) * np.sqrt(outputs))


HeD = HellingerDistance


class BinaryCrossEntropy(Objective):

    def __init__(self, epsilon=1e-11):
        self.epsilon = epsilon

    def forward(self, outputs, targets):
        outputs = np.clip(outputs, self.epsilon, 1 - self.epsilon)
        return np.mean(-np.sum(targets * np.log(outputs) + (1 - targets) * np.log(1 - outputs), axis=1))

    def backward(self, outputs, targets):
        outputs = np.clip(outputs, self.epsilon, 1 - self.epsilon)
        divisor = np.maximum(outputs * (1 - outputs), self.epsilon)
        return (outputs - targets) / divisor


BCE = BinaryCrossEntropy


class SoftmaxCategoricalCrossEntropy(Objective):

    def __init__(self, epsilon=1e-11):
        self.epsilon = epsilon

    def forward(self, outputs, targets):
        outputs = np.clip(outputs, self.epsilon, 1 - self.epsilon)
        return np.mean(-np.sum(targets * np.log(outputs), axis=1))

    def backward(self, outputs, targets):
        outputs = np.clip(outputs, self.epsilon, 1 - self.epsilon)
        return outputs - targets


SCCE = SoftmaxCategoricalCrossEntropy


def get(objective):
    if objective.__class__.__name__ == 'str':
        if objective in ['mse', 'MSE']:
            return MSE()
        if objective in ['mean_squared_error', 'MeanSquaredError']:
            return MeanSquaredError()
        if objective in ['hellinger_distance', 'HellingerDistance']:
            return HellingerDistance()
        if objective in ['hed', 'HeD']:
            return HeD()
        if objective in ['binary_cross_entropy', 'BinaryCrossEntropy']:
            return BinaryCrossEntropy()
        if objective in ['bce', 'BCE']:
            return BCE()
        if objective in ['softmax_categorical_cross_entropy', 'SoftmaxCategoricalCrossEntropy']:
            return SoftmaxCategoricalCrossEntropy()
        if objective in ['scce', 'SCCE']:
            return SCCE()
        raise ValueError('Unknown objective name: {}.'.format(objective))

    elif isinstance(objective, Objective):
        return copy.deepcopy(objective)

    else:
        raise ValueError("Unknown type: {}.".format(objective.__class__.__name__))


