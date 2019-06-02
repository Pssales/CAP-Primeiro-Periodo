import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

n, p = 10, .5 
binomial = np.random.binomial(n, p, 1000)
uniform = np.random.uniform(-1,0,1000)
beta = np.random.beta(1, 4, 1000)
laplace = np.random.laplace(0, 0.5, 1000)
gamma = np.random.gamma(1, 2, 1000)
exponential = np.random.exponential(1, 1000)
quiquadrado = np.random.chisquare(1, 1000)
cauchy = np.random.standard_cauchy(1000)
gaussian = np.random.normal(0, 0.2, 1000)
lognormal = np.random.lognormal(3, 1, 1000)
sns.distplot(beta)

sns.distplot(uniform, hist=False, color='red', label='Uniform')
sns.distplot(binomial, hist=False, color='blue', label='Binomial')
sns.distplot(beta, hist=False, color='blue', label='Beta')
sns.distplot(laplace, hist=False, color='blue', label='Laplace')
sns.distplot(gamma, hist=False, color='blue', label='Gamma')
sns.distplot(exponential, hist=False, color='blue', label='Exponential')
plt.show();