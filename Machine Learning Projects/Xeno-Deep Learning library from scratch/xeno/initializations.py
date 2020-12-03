import copy
import numpy as np

from xeno.utils.random import get_rng
from xeno.utils.random import get_dtype


class Initializer(object):
    
    def __call__(self, size):
        return self.call(size)

    def call(self, size):
        raise NotImplementedError()

    def __str__(self):
        return self.__class__.__name__


class Zero(Initializer):
    def call(self, size):
        return _cast_dtype(np.zeros(size))


class One(Initializer):
    def call(self, size):
        return _cast_dtype(np.ones(size))


class Uniform(Initializer):
    def __init__(self, scale=0.05):
        self.scale = scale

    def call(self, size):
        return _cast_dtype(get_rng().uniform(-self.scale, self.scale, size=size))


class Normal(Initializer):
    def __init__(self, std=0.01, mean=0.0):
        self.std = std
        self.mean = mean

    def call(self, size):
        return _cast_dtype(get_rng().normal(loc=self.mean, scale=self.std, size=size))


class LecunUniform(Initializer):
    def call(self, size):
        fan_in, fan_out = decompose_size(size)
        return Uniform(np.sqrt(3. / fan_in))(size)


class GlorotUniform(Initializer):
    def call(self, size):
        fan_in, fan_out = decompose_size(size)
        return Uniform(np.sqrt(6 / (fan_in + fan_out)))(size)


class GlorotNormal(Initializer):
    def call(self, size):
        fan_in, fan_out = decompose_size(size)
        return Normal(np.sqrt(2 / (fan_out + fan_in)))(size)


class HeNormal(Initializer):
    def call(self, size):
        fan_in, fan_out = decompose_size(size)
        return Normal(np.sqrt(2. / fan_in))(size)


class HeUniform(Initializer):
    def call(self, size):
        fan_in, fan_out = decompose_size(size)
        return Uniform(np.sqrt(6. / fan_in))(size)


class Orthogonal(Initializer):
    def __init__(self, gain=1.0):
        if gain == 'relu':
            gain = np.sqrt(2)
        self.gain = gain

    def call(self, size):
        flat_shape = (size[0], np.prod(size[1:]))
        a = get_rng().normal(loc=0., scale=1., size=flat_shape)
        u, _, v = np.linalg.svd(a, full_matrices=False)
        q = u if u.shape == flat_shape else v
        q = q.reshape(size)
        q = self.gain * q
        return _cast_dtype(q)


def decompose_size(size):
    if len(size) == 2:
        fan_in = size[0]
        fan_out = size[1]

    elif len(size) == 4 or len(size) == 5:
        respective_field_size = np.prod(size[2:])
        fan_in = size[1] * respective_field_size
        fan_out = size[0] * respective_field_size

    else:
        fan_in = fan_out = int(np.sqrt(np.prod(size)))

    return fan_in, fan_out


def _cast_dtype(res):
    return np.array(res, dtype=get_dtype())


_zero = Zero()
_one = One()


def get(initialization):
    if initialization.__class__.__name__ == 'str':
        if initialization in ['zero', 'Zero']:
            return Zero()
        if initialization in ['one', 'One']:
            return One()
        if initialization in ['uniform', 'Uniform']:
            return Uniform()
        if initialization in ['normal', 'Normal']:
            return Normal()
        if initialization in ['lecun_uniform', 'LecunUniform']:
            return LecunUniform()
        if initialization in ['glorot_uniform', 'GlorotUniform']:
            return GlorotUniform()
        if initialization in ['glorot_normal', 'GlorotNormal']:
            return GlorotNormal()
        if initialization in ['HeNormal', 'he_normal']:
            return HeNormal()
        if initialization in ['HeUniform', 'he_uniform']:
            return HeUniform()
        if initialization in ['Orthogonal', 'orthogonal']:
            return Orthogonal()
        raise ValueError('Unknown initialization name: {}.'.format(initialization))

    elif isinstance(initialization, Initializer):
        return copy.deepcopy(initialization)

    else:
        raise ValueError("Unknown type: {}.".format(initialization.__class__.__name__))

