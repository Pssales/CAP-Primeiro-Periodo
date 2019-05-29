from logistic import logistic

import matplotlib.pyplot as plt

rho = 4.00
a0 = 0.001
n_samples = 4096

S4 = logistic(rho, a0, n_samples)

plt.plot(S4)
plt.show()