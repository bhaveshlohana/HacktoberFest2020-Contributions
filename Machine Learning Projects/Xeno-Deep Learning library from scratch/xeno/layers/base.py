# -*- coding: utf-8 -*-


class Layer(object):
    first_layer = False

    def forward(self, input, *args, **kwargs):
        raise NotImplementedError

    def backward(self, pre_grad, *args, **kwargs):
        raise NotImplementedError

    def connect_to(self, prev_layer):
        raise NotImplementedError

    def to_json(self):
        raise NotImplementedError

    @classmethod
    def from_json(cls, config):
        return cls(**config)

    @property
    def params(self):
        return []

    @property
    def grads(self):
        return []

    @property
    def param_grads(self):
        return list(zip(self.params, self.grads))

    def __str__(self):
        return self.__class__.__name__