import numpy as np


def logistic(rho, a0, n):
    a = np.zeros(n)
    a[0] = a0
    for n in range(0, n-1, 1):
        a[n+1] = rho * a[n] * (1 - a[n])
    return a
