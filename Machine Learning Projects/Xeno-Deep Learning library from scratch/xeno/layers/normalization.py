# -*- coding: utf-8 -*-


import numpy as np

from .base import Layer
from .. import initializations


class BatchNormal(Layer):
    

    def __init__(self, epsilon=1e-6, momentum=0.9, axis=0,
                 beta_init='zero', gamma_init='one'):
        self.epsilon = epsilon
        self.momentum = momentum
        self.axis = axis

        self.beta_init = initializations.get(beta_init)
        self.gamma_init = initializations.get(gamma_init)

        self.beta, self.dbeta = None, None
        self.gamma, self.dgamma = None, None
        self.cache = None

    def connect_to(self, prev_layer):
        n_in = prev_layer.out_shape[-1]

        self.beta = self.beta_init((n_in,))
        self.gamma = self.gamma_init((n_in,))

    def forward(self, input, *args, **kwargs):
        # N, D = x.shape
        # # 为了后向传播求导方便，这里都是分步进行的

        # step1: calculate the mean
        # mu = 1. / N * np.sum(x, axis=0)
        mean = np.mean(input, axis=0)

        # step2: 减均值
        xmu = input - mean

        # step3: 计算方差
        # sq = xmu ** 2
        # var = 1. / N * np.sum(sq, axis=0)
        var = np.std(xmu, axis=0)

        # step4: 计算x^的分母项
        sqrtvar = np.sqrt(var + self.epsilon)
        ivar = 1. / sqrtvar

        # step5: normalization->x^
        xhat = xmu * ivar

        # step6: scale and shift
        gammax = self.gamma * xhat
        out = gammax + self.beta

        # 存储中间变量
        self.cache = (xhat, xmu, ivar, sqrtvar, var)

        return out

    def backward(self, pre_grad, *args, **kwargs):
        # 解压中间变量
        xhat, xmu, ivar, sqrtvar, var = self.cache

        N, D = pre_grad.shape

        # step6
        self.dbeta = np.sum(pre_grad, axis=0)
        dgammax = pre_grad
        self.dgamma = np.sum(dgammax * xhat, axis=0)
        dxhat = dgammax * self.gamma

        # step5
        divar = np.sum(dxhat * xmu, axis=0)
        dxmu1 = dxhat * ivar  # 注意这是xmu的一个支路

        # step4
        dsqrtvar = -1. / (sqrtvar ** 2) * divar
        dvar = 0.5 * 1. / np.sqrt(var + self.epsilon) * dsqrtvar

        # step3
        dsq = 1. / N * np.ones((N, D)) * dvar
        dxmu2 = 2 * xmu * dsq  # 注意这是xmu的第二个支路

        # step2, 注意这是x的一个支路
        dx1 = (dxmu1 + dxmu2)

        # step1, 注意这是x的第二个支路
        dmu = -1 * np.sum(dxmu1 + dxmu2, axis=0)
        dx2 = 1. / N * np.ones((N, D)) * dmu

        # step0 done!
        dx = dx1 + dx2

        return dx

    @property
    def params(self):
        return self.beta, self.gamma

    @property
    def grades(self):
        return self.dbeta, self.dgamma
