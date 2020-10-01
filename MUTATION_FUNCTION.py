#!/usr/bin/env python3

T = int(input())

for tidx in range(1, T + 1):
    n = int(input())

    a = n
    b = 0

    a_str = str(a)
    len_str = len(a_str)
    for i in range(len(a_str)):
        if a_str[i] == '4':
            coef = 10 ** (len_str - i - 1)
            b += coef
            a -= coef

    print("Case #{}: {} {}".format(tidx, a, b))

