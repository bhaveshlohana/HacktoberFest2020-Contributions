# -*- coding: utf-8 -*-


import numpy as np

from .base import Layer
from .. import activations
from .. import initializations
from ..initializations import _one
from ..initializations import _zero


class Recurrent(Layer):
    
    def __init__(self, n_out, n_in=None, nb_batch=None, nb_seq=None,
                 init='glorot_uniform', inner_init='orthogonal',
                 activation='tanh', return_sequence=False):
        self.n_out = n_out
        self.n_in = n_in
        self.nb_batch = nb_batch
        self.nb_seq = nb_seq
        self.init = initializations.get(init)
        self.inner_init = initializations.get(inner_init)
        self.activation_cls = activations.get(activation).__class__
        self.activation = activations.get(activation)
        self.return_sequence = return_sequence

        self.out_shape = None
        self.last_input = None
        self.last_output = None

    def connect_to(self, prev_layer=None):
        if prev_layer is not None:
            assert len(prev_layer.out_shape) == 3
            self.n_in = prev_layer.out_shape[-1]
            self.nb_batch = prev_layer.out_shape[0] or self.nb_batch
            self.nb_seq = prev_layer.out_shape[1] or self.nb_seq

        else:
            assert self.n_in is not None

        if self.return_sequence:
            self.out_shape = (self.nb_batch, self.nb_seq, self.n_out)
        else:
            self.out_shape = (self.nb_batch, self.n_out)


class SimpleRNN(Recurrent):
    

    def __init__(self, **kwargs):
        super(SimpleRNN, self).__init__(**kwargs)

        self.W, self.dW = None, None
        self.U, self.dU = None, None
        self.b, self.db = None, None
        self.activations = []

    def connect_to(self, prev_layer=None):
        super(SimpleRNN, self).connect_to(prev_layer)

        self.W = self.init((self.n_in, self.n_out))
        self.U = self.inner_init((self.n_out, self.n_out))
        self.b = _zero((self.n_out,))

    def forward(self, input, *args, **kwargs):
        assert np.ndim(input) == 3, 'Only support batch training.'

        self.last_input = input
        nb_batch, nb_timestep, nb_in = input.shape
        output = _zero((nb_batch, nb_timestep, self.n_out))

        if len(self.activations) == 0:
            self.activations = [self.activation_cls() for _ in range(nb_timestep)]

        output[:, 0, :] = self.activations[0].forward(np.dot(input[:, 0, :], self.W) + self.b)

        for i in range(1, nb_timestep):
            output[:, i, :] = self.activations[i].forward(
                np.dot(input[:, i, :], self.W) +
                np.dot(output[:, i - 1, :], self.U) + self.b)

        self.last_output = output
        if self.return_sequence:
            return self.last_output
        else:
            return self.last_output[:, -1, :]

    def backward(self, pre_grad, *args, **kwargs):
        self.dW = _zero(self.W.shape)
        self.dU = _zero(self.U.shape)
        self.db = _zero(self.b.shape)

        # hiddens.shape == (nb_timesteps, nb_batch, nb_out)
        hiddens = np.transpose(self.last_output, (1, 0, 2))
        if self.return_sequence:
            # check shape
            pre_grad = np.transpose(pre_grad, (1, 0, 2))
            assert hiddens.shape == pre_grad.shape
            nb_timesteps = pre_grad.shape[0]
            layer_grad = _zero(pre_grad.shape)

            for timestep1 in np.arange(nb_timesteps)[::-1]:
                delta = pre_grad[timestep1] * self.activations[timestep1].derivative()
                for timestep2 in np.arange(timestep1)[::-1]:
                    self.dU += np.dot(hiddens[timestep2].T, delta)
                    self.dW += np.dot(self.last_input[:, timestep2 + 1, :].T, delta)
                    self.db += np.mean(delta, axis=0)
                    if not self.first_layer:
                        layer_grad[timestep2 + 1] += np.dot(delta, self.W.T)
                    delta = np.dot(delta, self.U.T)

                if timestep1 == 0 or timestep2 == 0:
                    self.dW += np.dot(self.last_input[:, 0, :].T, delta)
                    self.db += np.mean(delta, axis=0)
                    if not self.first_layer:
                        layer_grad[0] += np.dot(delta, self.W.T)

        else:
            nb_timesteps = self.last_output.shape[1]
            nb_batchs = self.last_output.shape[0]
            assert (nb_batchs, self.last_output.shape[2]) == pre_grad.shape
            layer_grad = _zero(hiddens.shape)

            delta = pre_grad * self.activations[nb_timesteps - 1].derivative()
            for timestep2 in np.arange(nb_timesteps - 1)[::-1]:
                self.dU += np.dot(hiddens[timestep2].T, delta)
                self.dW += np.dot(self.last_input[:, timestep2 + 1, :].T, delta)
                self.db += np.mean(delta, axis=0)
                if not self.first_layer:
                    layer_grad[timestep2 + 1] += np.dot(delta, self.W.T)
                delta = np.dot(delta, self.U.T)

            if timestep2 == 0:
                self.dW += np.dot(self.last_input[:, timestep2 + 1, :].T, delta)
                self.db += np.mean(delta, axis=0)
                if not self.first_layer:
                    layer_grad[0] += np.dot(delta, self.W.T)

        if not self.first_layer:
            return np.transpose(layer_grad, (1, 0, 2))

    @property
    def params(self):
        return self.W, self.U, self.b

    @property
    def grads(self):
        return self.dW, self.dU, self.db


class GRU(Recurrent):
    
    def __init__(self, gate_activation='sigmoid', need_grad=True, **kwargs):
        super(GRU, self).__init__(**kwargs)

        self.gate_activation_cls = activations.get(gate_activation).__class__
        self.gate_activation = activations.get(gate_activation)
        self.need_grad = need_grad

        self.U_r, self.U_z, self.U_h = None, None, None
        self.W_r, self.W_z, self.W_h = None, None, None
        self.b_r, self.b_z, self.b_h = None, None, None

        self.grad_U_r, self.grad_U_z, self.grad_U_h = None, None, None
        self.grad_W_r, self.grad_W_z, self.grad_W_h = None, None, None
        self.grad_b_r, self.grad_b_z, self.grad_b_h = None, None, None

    def connect_to(self, prev_layer=None):
        super(GRU, self).connect_to(prev_layer)

        # Weights matrices for input x
        self.U_r = self.init((self.n_in, self.n_out))
        self.U_z = self.init((self.n_in, self.n_out))
        self.U_h = self.init((self.n_in, self.n_out))

        # Weights matrices for memory cell
        self.W_r = self.inner_init((self.n_out, self.n_out))
        self.W_z = self.inner_init((self.n_out, self.n_out))
        self.W_h = self.inner_init((self.n_out, self.n_out))

        # Biases
        self.b_r = _zero((self.n_out,))
        self.b_z = _zero((self.n_out,))
        self.b_h = _zero((self.n_out,))

    def forward(self, input, *args, **kwargs):
        assert np.ndim(input) == 3, 'Only support batch training.'

        # record
        self.last_input = input

        # dim
        nb_batch, nb_timesteps, nb_in = input.shape

        # outputs
        output = _zero((nb_batch, nb_timesteps, self.n_out))

        # forward
        for i in range(nb_timesteps):
            # data
            s_pre = _zero((nb_batch, self.n_out)) if i == 0 else output[:, i - 1, :]
            x_now = input[:, i, :]

            # computation
            z_now = self.gate_activation.forward(np.dot(x_now, self.U_z) +
                                                 np.dot(s_pre, self.W_z) +
                                                 self.b_z)
            r_now = self.gate_activation.forward(np.dot(x_now, self.U_r) +
                                                 np.dot(s_pre, self.W_r) +
                                                 self.b_r)
            h_now = self.activation.forward(np.dot(x_now, self.U_h) +
                                            np.dot(s_pre * r_now, self.W_h) +
                                            self.b_h)
            output[:, i, :] = (1 - z_now) * h_now + z_now * s_pre

        # record
        self.last_output = output

        # return
        if self.return_sequence:
            return self.last_output
        else:
            return self.last_output[:, -1, :]

    def backward(self, pre_grad, *args, **kwargs):
        raise NotImplementedError

    @property
    def params(self):
        return self.U_r, self.U_z, self.U_h, \
               self.W_r, self.W_z, self.W_h, \
               self.b_r, self.b_z, self.b_h

    @property
    def grads(self):
        return self.grad_U_r, self.grad_U_z, self.grad_U_h, \
               self.grad_W_r, self.grad_W_z, self.grad_W_h, \
               self.grad_b_r, self.grad_b_z, self.grad_b_h


class LSTM(Recurrent):
    
    def __init__(self, gate_activation="sigmoid", need_grad=True, forget_bias_num=1, **kwargs):
        super(LSTM, self).__init__(**kwargs)

        self.gate_activation_cls = activations.get(gate_activation).__class__
        self.gate_activation = activations.get(gate_activation)
        self.need_grad = need_grad
        self.forget_bias_num = forget_bias_num

        self.U_g, self.U_i, self.U_f, self.U_o = None, None, None, None
        self.W_g, self.W_i, self.W_f, self.W_o = None, None, None, None
        self.b_g, self.b_i, self.b_f, self.b_o = None, None, None, None

        self.grad_U_g, self.grad_U_i, self.grad_U_f, self.grad_U_o = None, None, None, None
        self.grad_W_g, self.grad_W_i, self.grad_W_f, self.grad_W_o = None, None, None, None
        self.grad_b_g, self.grad_b_i, self.grad_b_f, self.grad_b_o = None, None, None, None

        self.c0, self.h0 = None, None
        self.last_cell = None

    def connect_to(self, prev_layer=None):
        super(LSTM, self).connect_to(prev_layer)

        # Weights matrices for input x
        self.U_g = self.init((self.n_in, self.n_out))
        self.U_i = self.init((self.n_in, self.n_out))
        self.U_f = self.init((self.n_in, self.n_out))
        self.U_o = self.init((self.n_in, self.n_out))

        # Weights matrices for memory cell
        self.W_g = self.inner_init((self.n_out, self.n_out))
        self.W_i = self.inner_init((self.n_out, self.n_out))
        self.W_f = self.inner_init((self.n_out, self.n_out))
        self.W_o = self.inner_init((self.n_out, self.n_out))

        # Biases
        self.b_g = _zero((self.n_out,))
        self.b_i = _zero((self.n_out,))
        self.b_f = _one((self.n_out,)) * self.forget_bias_num
        self.b_o = _zero((self.n_out,))

    def forward(self, input, mask, c0=None, h0=None):
        assert np.ndim(input) == 3, 'Only support batch training.'

        # record
        self.last_input = input

        # dim
        nb_batch, nb_timesteps, nb_in = input.shape

        # data
        output = _zero((nb_batch, nb_timesteps, self.n_out))
        cell = _zero((nb_batch, nb_timesteps, self.n_out))
        self.c0 = _zero((nb_batch, self.n_out)) if c0 is None else c0
        self.h0 = _zero((nb_batch, self.n_out)) if h0 is None else h0

        # forward
        for t in range(nb_timesteps):
            # data
            h_pre = self.h0 if t == 0 else output[:, t - 1, :]
            c_pre = self.c0 if t == 0 else cell[:, t - 1, :]
            x_now = input[:, t, :]
            m_now = mask[:, t]

            # computation
            f = self.gate_activation.forward(np.dot(x_now, self.U_f) +
                                             np.dot(h_pre, self.W_f) +
                                             self.b_f)
            i = self.gate_activation.forward(np.dot(x_now, self.U_i) +
                                             np.dot(h_pre, self.W_i) +
                                             self.b_i)
            o = self.gate_activation.forward(np.dot(x_now, self.U_o) +
                                             np.dot(h_pre, self.W_o) +
                                             self.b_o)
            g = self.activation.forward(np.dot(x_now, self.U_g) +
                                        np.dot(h_pre, self.W_g) +
                                        self.b_g)
            c = f * c_pre + i * g
            c = m_now[:, None] * c + (1.0 - m_now)[:, None] * c_pre

            h = o * self.activation.forward(c)
            h = m_now[:, None] * h + (1.0 - m_now)[:, None] * h_pre

            # record
            self.h0 = h
            self.c0 = c
            output[:, t, :] = h
            cell[:, t, :] = c

        # record
        self.last_output = output
        self.last_cell = cell

        # return
        if self.return_sequence:
            return self.last_output
        else:
            return self.last_output[:, -1, :]

    def backward(self, pre_grad, *args, **kwargs):
        # reset
        self.grad_W_g = _zero(self.W_g.shape)
        self.grad_W_i = _zero(self.W_i.shape)
        self.grad_W_f = _zero(self.W_f.shape)
        self.grad_W_o = _zero(self.W_o.shape)

        self.grad_U_g = _zero(self.U_g.shape)
        self.grad_U_i = _zero(self.U_i.shape)
        self.grad_U_f = _zero(self.U_f.shape)
        self.grad_U_o = _zero(self.U_o.shape)

        self.grad_b_g = _zero(self.b_g.shape)
        self.grad_b_i = _zero(self.b_i.shape)
        self.grad_b_f = _zero(self.b_f.shape)
        self.grad_b_o = _zero(self.b_o.shape)

        # backward
        raise NotImplementedError

    @property
    def params(self):
        return self.U_g, self.U_i, self.U_f, self.U_o, \
               self.W_g, self.W_i, self.W_f, self.W_o, \
               self.b_g, self.b_i, self.b_f, self.b_o

    @property
    def grads(self):
        return self.grad_U_g, self.grad_U_i, self.grad_U_f, self.grad_U_o, \
               self.grad_W_g, self.grad_W_i, self.grad_W_f, self.grad_W_o, \
               self.grad_b_g, self.grad_b_i, self.grad_b_f, self.grad_b_o


class BatchLSTM(Recurrent):
    
    def __init__(self, gate_activation='sigmoid', need_grad=True,
                 forget_bias_num=1, **kwargs):
        super(BatchLSTM, self).__init__(**kwargs)

        self.gate_activation_cls = activations.get(gate_activation).__class__
        self.gate_activation = activations.get(gate_activation)
        self.need_grad = need_grad
        self.forget_bias_num = forget_bias_num

        self.AllW, self.d_AllW = None, None
        self.c0, self.d_c0 = None, None
        self.h0, self.d_h0 = None, None
        self.IFOGf = None
        self.IFOG = None
        self.Hin = None
        self.Ct = None
        self.C = None

    def connect_to(self, prev_layer=None):
        
        super(BatchLSTM, self).connect_to(prev_layer)
        n_in = self.n_in
        n_out = self.n_out

        # init weights
        self.AllW = _zero((n_in + n_out + 1, 4 * n_out))

        # bias
        if self.forget_bias_num != 0:
            self.AllW[0, self.n_out: 2 * self.n_out] = self.forget_bias_num
        # Weights matrices for input x
        self.AllW[1:n_in + 1, n_out * 0:n_out * 1] = self.init((n_in, n_out))
        self.AllW[1:n_in + 1, n_out * 1:n_out * 2] = self.init((n_in, n_out))
        self.AllW[1:n_in + 1, n_out * 2:n_out * 3] = self.init((n_in, n_out))
        self.AllW[1:n_in + 1, n_out * 3:n_out * 4] = self.init((n_in, n_out))
        # Weights matrices for memory cell
        self.AllW[n_in + 1:, n_out * 0:n_out * 1] = self.inner_init((n_out, n_out))
        self.AllW[n_in + 1:, n_out * 1:n_out * 2] = self.inner_init((n_out, n_out))
        self.AllW[n_in + 1:, n_out * 2:n_out * 3] = self.inner_init((n_out, n_out))
        self.AllW[n_in + 1:, n_out * 3:n_out * 4] = self.inner_init((n_out, n_out))

    def forward(self, input, c0=None, h0=None):
        

        # checking
        assert np.ndim(input) == 3, 'Only support batch training.'
        assert input.shape[2] == self.n_in

        # shape
        nb_batch, nb_seq, n_in = input.shape
        self.nb_batch = nb_batch
        self.nb_seq = nb_seq

        # data
        input = np.transpose(input, (1, 0, 2))
        self.c0 = _zero((nb_batch, self.n_out)) if c0 is None else c0
        self.h0 = _zero((nb_batch, self.n_out)) if h0 is None else h0

        # Perform the LSTM forward pass with X as the input #
        # x plus h plus bias, lol
        xphpb = self.AllW.shape[0]
        # input [1, xt, ht-1] to each tick of the LSTM
        Hin = _zero((nb_seq, nb_batch, xphpb))
        # hidden representation of the LSTM (gated cell content)
        Hout = _zero((nb_seq, nb_batch, self.n_out))
        # input, forget, output, gate (IFOG)
        IFOG = _zero((nb_seq, nb_batch, self.n_out * 4))
        # after nonlinearity
        IFOGf = _zero((nb_seq, nb_batch, self.n_out * 4))
        # cell content
        C = _zero((nb_seq, nb_batch, self.n_out))
        # tanh of cell content
        Ct = _zero((nb_seq, nb_batch, self.n_out))
        for t in range(nb_seq):
            # concat [x,h] as input to the LSTM
            prevh = Hout[t - 1] if t > 0 else self.h0
            # bias
            Hin[t, :, 0] = 1
            Hin[t, :, 1:n_in + 1] = input[t]
            Hin[t, :, n_in + 1:] = prevh
            # compute all gate activations. dots: (most work is this line)
            IFOG[t] = Hin[t].dot(self.AllW)
            # non-linearities
            # sigmoids; these are the gates
            IFOGf[t, :, :3 * self.n_out] = 1.0 / (1.0 + np.exp(-IFOG[t, :, :3 * self.n_out]))
            # tanh
            IFOGf[t, :, 3 * self.n_out:] = np.tanh(IFOG[t, :, 3 * self.n_out:])
            # compute the cell activation
            prevc = C[t - 1] if t > 0 else self.c0
            C[t] = IFOGf[t, :, :self.n_out] * IFOGf[t, :, 3 * self.n_out:] + \
                   IFOGf[t, :, self.n_out:2 * self.n_out] * prevc
            Ct[t] = np.tanh(C[t])
            Hout[t] = IFOGf[t, :, 2 * self.n_out:3 * self.n_out] * Ct[t]

        # record
        self.last_output = np.transpose(Hout, (1, 0, 2))
        self.IFOGf = IFOGf
        self.IFOG = IFOG
        self.Hin = Hin
        self.Ct = Ct
        self.C = C

        if self.return_sequence:
            return self.last_output
        else:
            return self.last_output[:, -1, :]

    def backward(self, pre_grad, dcn=None, dhn=None):
        
        Hout = np.transpose(self.last_output, (1, 0, 2))
        nb_seq, batch_size, n_out = Hout.shape
        input_size = self.AllW.shape[0] - n_out - 1  # -1 due to bias

        self.d_AllW = _zero(self.AllW.shape)
        self.d_h0 = _zero((batch_size, n_out))

        # backprop the LSTM
        dIFOG = _zero(self.IFOG.shape)
        dIFOGf = _zero(self.IFOGf.shape)
        dHin = _zero(self.Hin.shape)
        dC = _zero(self.C.shape)
        layer_grad = _zero((nb_seq, batch_size, input_size))
        # make a copy so we don't have any funny side effects

        # prepare layer gradients
        if self.return_sequence:
            timesteps = list(range(nb_seq))[::-1]
            assert np.ndim(pre_grad) == 3
        else:
            timesteps = [nb_seq - 1]
            assert np.ndim(pre_grad) == 2
            tmp = _zero((self.nb_batch, self.nb_seq, self.n_out))
            tmp[:, -1, :] = pre_grad
            pre_grad = tmp
        dHout = np.transpose(pre_grad, (1, 0, 2)).copy()

        # carry over gradients from later
        if dcn is not None: dC[nb_seq - 1] += dcn.copy()
        if dhn is not None: dHout[nb_seq - 1] += dhn.copy()

        for t in timesteps:

            tanhCt = self.Ct[t]
            dIFOGf[t, :, 2 * n_out:3 * n_out] = tanhCt * dHout[t]
            # backprop tanh non-linearity first then continue backprop
            dC[t] += (1 - tanhCt ** 2) * (self.IFOGf[t, :, 2 * n_out:3 * n_out] * dHout[t])

            if t > 0:
                dIFOGf[t, :, n_out:2 * n_out] = self.C[t - 1] * dC[t]
                dC[t - 1] += self.IFOGf[t, :, n_out:2 * n_out] * dC[t]
            else:
                dIFOGf[t, :, n_out:2 * n_out] = self.c0 * dC[t]
                self.d_c0 = self.IFOGf[t, :, n_out:2 * n_out] * dC[t]
            dIFOGf[t, :, :n_out] = self.IFOGf[t, :, 3 * n_out:] * dC[t]
            dIFOGf[t, :, 3 * n_out:] = self.IFOGf[t, :, :n_out] * dC[t]

            # backprop activation functions
            dIFOG[t, :, 3 * n_out:] = (1 - self.IFOGf[t, :, 3 * n_out:] ** 2) * dIFOGf[t, :, 3 * n_out:]
            y = self.IFOGf[t, :, :3 * n_out]
            dIFOG[t, :, :3 * n_out] = (y * (1.0 - y)) * dIFOGf[t, :, :3 * n_out]

            # backprop matrix multiply
            self.d_AllW += np.dot(self.Hin[t].transpose(), dIFOG[t])
            dHin[t] = dIFOG[t].dot(self.AllW.transpose())

            # backprop the identity transforms into Hin
            layer_grad[t] = dHin[t, :, 1:input_size + 1]
            if t > 0:
                dHout[t - 1, :] += dHin[t, :, input_size + 1:]
            else:
                self.d_h0 += dHin[t, :, input_size + 1:]

        layer_grad = np.transpose(layer_grad, (1, 0, 2))
        return layer_grad

    @property
    def params(self):
        return [self.AllW, ]

    @property
    def grads(self):
        return [self.d_AllW, ]
