import copy
import numpy as np

from .initializations import _zero


class Optimizer(object):
    
    def __init__(self, lr=0.001, clip=-1, decay=0., lr_min=0., lr_max=np.inf):
        self.lr = lr
        self.clip = clip
        self.decay = decay
        self.lr_min = lr_min
        self.lr_max = lr_max

        self.iterations = 0

    def update(self, params, grads):
        
        self.iterations += 1

        self.lr *= (1. / 1 + self.decay * self.iterations)
        self.lr = np.clip(self.lr, self.lr_min, self.lr_max)

    def __str__(self):
        return self.__class__.__name__


class SGD(Optimizer):

    def __init__(self, *args, **kwargs):
        super(SGD, self).__init__(*args, **kwargs)

    def update(self, params, grads):
        for p, g in zip(params, grads):
            p -= self.lr * npdl_clip(g, self.clip)

        super(SGD, self).update(params, grads)


class Momentum(Optimizer):

    def __init__(self, momentum=0.9, *args, **kwargs):
        super(Momentum, self).__init__(*args, **kwargs)

        self.momentum = momentum

        self.velocity = None

    def update(self, params, grads):
        # init the velocities
        if self.velocity is None:
            self.velocity = [_zero(p.shape) for p in params]

        # update the parameters
        for i, (v, p, g) in enumerate(zip(self.velocity, params, grads)):
            v = self.momentum * v - self.lr * g
            p += v
            self.velocity[i] = v

        super(Momentum, self).update(params, grads)


class NesterovMomentum(Optimizer):
    
    def __init__(self, momentum=0.9, *args, **kwargs):
        super(NesterovMomentum, self).__init__(*args, **kwargs)

        self.momentum = momentum

        self.velocity = None

    def update(self, params, grads):
        # init the velocities
        if self.velocity is None:
            self.velocity = [_zero(p.shape) for p in params]

        # update the parameters
        for i, (v, p, g) in enumerate(zip(self.velocity, params, grads)):
            v = self.momentum * v - self.lr * g
            p += (self.momentum * v - self.lr * g)
            self.velocity[i] = v

        super(NesterovMomentum, self).update(params, grads)


class Adagrad(Optimizer):
    
    def __init__(self, epsilon=1e-6, *args, **kwargs):
        super(Adagrad, self).__init__(*args, **kwargs)

        self.epsilon = epsilon

        self.cache = None

    def update(self, params, grads):
        # init cache
        if self.cache is None:
            self.cache = [_zero(g.shape) for g in grads]

        # update parameters
        for i, (c, p, g) in enumerate(zip(self.cache, params, grads)):
            c += np.power(g, 2)
            p -= self.lr * g / (np.sqrt(c) + self.epsilon)
            self.cache[i] = c

        super(Adagrad, self).update(params, grads)


class RMSprop(Optimizer):
    
    def __init__(self, rho=0.9, epsilon=1e-6, *args, **kwargs):
        super(RMSprop, self).__init__(*args, **kwargs)

        self.rho = rho
        self.epsilon = epsilon

        self.cache = None
        self.iterations = 0

    def update(self, params, grads):
        # init cache
        if self.cache is None:
            self.cache = [_zero(p.shape) for p in params]

        # update parameters
        for i, (c, p, g) in enumerate(zip(self.cache, params, grads)):
            c = self.rho * c + (1 - self.rho) * np.power(g, 2)
            p -= (self.lr * g / np.sqrt(c + self.epsilon))
            self.cache[i] = c


class Adadelta(Optimizer):
    


    def __init__(self, rho=0.9, epsilon=1e-6, *args, **kwargs):
        super(Adadelta, self).__init__(*args, **kwargs)

        self.rho = rho
        self.epsilon = epsilon

        self.cache = None
        self.delta = None

    def update(self, params, grads):
        # init cache and delta
        if self.cache is None:
            self.cache = [_zero(p.shape) for p in params]
        if self.delta is None:
            self.delta = [_zero(p.shape) for p in params]

        # update parameters
        for i, (c, d, p, g) in enumerate(zip(self.cache, self.delta, params, grads)):
            c = self.rho * c + (1 - self.rho) * np.power(g, 2)
            update = g * np.sqrt(d + self.epsilon) / np.sqrt(c + self.epsilon)
            p -= self.lr * update
            d = self.rho * d + (1 - self.rho) * np.power(update, 2)

            self.cache[i] = c
            self.delta[i] = d


class Adam(Optimizer):
    


    def __init__(self, beta1=0.9, beta2=0.999, epsilon=1e-8, *args, **kwargs):
        super(Adam, self).__init__(*args, **kwargs)

        self.beta1 = beta1
        self.beta2 = beta2
        self.epsilon = epsilon

        self.ms = None
        self.vs = None

    def update(self, params, grads):
        # init
        self.iterations += 1
        a_t = self.lr * np.sqrt(1 - np.power(self.beta2, self.iterations)) / \
              (1 - np.power(self.beta1, self.iterations))
        if self.ms is None:
            self.ms = [_zero(p.shape) for p in params]
        if self.vs is None:
            self.vs = [_zero(p.shape) for p in params]

        # update parameters
        for i, (m, v, p, g) in enumerate(zip(self.ms, self.vs, params, grads)):
            m = self.beta1 * m + (1 - self.beta1) * g
            v = self.beta2 * v + (1 - self.beta2) * np.power(g, 2)
            p -= a_t * m / (np.sqrt(v) + self.epsilon)

            self.ms[i] = m
            self.vs[i] = v


class Adamax(Optimizer):
    


    def __init__(self, beta1=0.9, beta2=0.999, epsilon=1e-8, *args, **kwargs):
        super(Adamax, self).__init__(*args, **kwargs)

        self.beta1 = beta1
        self.beta2 = beta2
        self.epsilon = epsilon

        self.ms = None
        self.vs = None

    def update(self, params, grads):
        # init
        self.iterations += 1
        a_t = self.lr / (1 - np.power(self.beta1, self.iterations))
        if self.ms is None:
            self.ms = [_zero(p.shape) for p in params]
        if self.vs is None:
            self.vs = [_zero(p.shape) for p in params]

        # update parameters
        for i, (m, v, p, g) in enumerate(zip(self.ms, self.vs, params, grads)):
            m = self.beta1 * m + (1 - self.beta1) * g
            v = np.maximum(self.beta2 * v, np.abs(g))
            p -= a_t * m / (v + self.epsilon)

            self.ms[i] = m
            self.vs[i] = v


def npdl_clip(grad, boundary):
    if boundary > 0:
        return np.clip(grad, -boundary, boundary)
    else:
        return grad


def get(optimizer):
    if optimizer.__class__.__name__ == 'str':
        if optimizer in ['sgd', 'SGD']:
            return SGD()
        if optimizer in ['momentum', 'Momentum']:
            return Momentum()
        if optimizer in ['nesterov_momentum', 'NesterovMomentum']:
            return NesterovMomentum()
        if optimizer in ['adagrad', 'Adagrad']:
            return Adagrad()
        if optimizer in ['rmsprop', 'RMSprop']:
            return RMSprop()
        if optimizer in ['adadelta', 'Adadelta']:
            return Adadelta()
        if optimizer in ['adam', 'Adam']:
            return Adam()
        if optimizer in ['adamax', 'Adamax']:
            return Adamax()
        raise ValueError('Unknown optimizer name: {}.'.format(optimizer))

    elif isinstance(optimizer, Optimizer):
        return copy.deepcopy(optimizer)

    else:
        raise ValueError("Unknown type: {}.".format(optimizer.__class__.__name__))
