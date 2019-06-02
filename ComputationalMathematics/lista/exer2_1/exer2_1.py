import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

n, p = 10, .5 
binomial = np.random.binomial(n, p, 4096)
uniform = np.random.uniform(-1,0,4096)
beta = np.random.beta(1, 4, 4096)
laplace = np.random.laplace(0, 0.5, 4096)
gamma = np.random.gamma(1, 2, 4096)
exponential = np.random.exponential(1, 4096)
quiquadrado = np.random.chisquare(1, 4096)
cauchy = np.random.standard_cauchy(4096)
gaussian = np.random.normal(0, 0.2, 4096)
lognormal = np.random.lognormal(3, 1, 4096)
sns.distplot(beta)

sns.distplot(uniform, hist=False, color='red', label='Uniform')
sns.distplot(binomial, hist=False, color='blue', label='Binomial')
sns.distplot(beta, hist=False, color='green', label='Beta')
sns.distplot(laplace, hist=False, color='black', label='Laplace')
sns.distplot(gamma, hist=False, color='y', label='Gamma')
sns.distplot(exponential, hist=False, color='c', label='Exponential')
plt.show();