import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

plt.figure(figsize=(10, 5))

low, high = -1, 1
uniform = np.random.uniform(low, high, 1000)
sns.distplot(uniform, color='green', label='low=-1, high=1', hist=False)

low, high = 1, 4
uniform = np.random.uniform(low, high, 1000)
sns.distplot(uniform, color='red', label='low=1, high=4', hist=False)

low, high = 4, 10
uniform = np.random.uniform(low, high, 1000)
sns.distplot(uniform, color='blue', label='low=4, high=10', hist=False)

plt.title('Uniform Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Observation')
plt.ylabel('Relative Frequency')
plt.legend(loc='best')
plt.show()

plt.figure(figsize=(10, 5))

n, p = 20, 0.25
binomial = np.random.binomial(n, p, 1000)
sns.distplot(binomial, color='green', label='n=20, p=0.25', hist=False)

n, p = 20, 0.5
binomial = np.random.binomial(n, p, 1000)
sns.distplot(binomial, color='red', label='n=20, p=0.5', hist=False)

n, p = 20, 0.75
binomial = np.random.binomial(n, p, 1000)
sns.distplot(binomial, color='blue', label='n=20, p=0.75', hist=False)

plt.title('Binomial Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Random Variable')
plt.ylabel('Probability')
plt.legend(loc='best')
plt.show()

plt.figure(figsize=(10, 5))

alpha, beta = 2, 8
beta = np.random.beta(alpha, beta, 1000)
sns.distplot(beta, color='green', label='alpha=2, beta=8', hist=False)

alpha, beta = 5, 5
beta = np.random.beta(alpha, beta, 1000)
sns.distplot(beta, color='red', label='alpha=5, beta=5', hist=False)

alpha, beta = 8, 2
beta = np.random.beta(alpha, beta, 1000)
sns.distplot(beta, color='blue', label='alpha=8, beta=2', hist=False)

plt.title('Beta Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Probability')
plt.ylabel('Density')
plt.legend(loc='best')
plt.show()

plt.figure(figsize=(10, 5))

loc, scale = 0, 1
laplace = np.random.laplace(loc, scale, 1000)
sns.distplot(laplace, color='green', label='mi=0, beta=1', hist=False)

loc, scale = 0, 2
laplace = np.random.laplace(loc, scale, 1000)
sns.distplot(laplace, color='red', label='mi=0, beta=2', hist=False)

loc, scale = 0, 4
laplace = np.random.laplace(loc, scale, 1000)
sns.distplot(laplace, color='blue', label='mi=0, beta=4', hist=False)

plt.title('Laplace Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Random Variable')
plt.ylabel('Probability')
plt.legend(loc='best')
plt.show()

plt.figure(figsize=(10, 5))

alpha, beta = 1, 1
gamma = np.random.gamma(alpha, beta, 1000)
sns.distplot(gamma, color='green', label='alpha=1, beta=1', hist=False)

alpha, beta = 2, 1
gamma = np.random.gamma(alpha, beta, 1000)
sns.distplot(gamma, color='red', label='alpha=2, beta=1', hist=False)

alpha, beta = 3, 1
gamma = np.random.gamma(alpha, beta, 1000)
sns.distplot(gamma, color='blue', label='alpha=3, beta=1', hist=False)

plt.title('Gamma Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Random Variable')
plt.ylabel('Probability')
plt.legend(loc='best')
plt.show()

plt.figure(figsize=(10, 5))

scale = 5
exponential = np.random.exponential(scale, 1000)
sns.distplot(exponential, color='green', label='scale=5', hist=False)

scale = 2
exponential = np.random.exponential(scale, 1000)
sns.distplot(exponential, color='red', label='scale=2', hist=False)

scale = 1
exponential = np.random.exponential(scale, 1000)
sns.distplot(exponential, color='blue', label='scale=1', hist=False)

plt.title('Exponential Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Random Variable')
plt.ylabel('Probability')
plt.legend(loc='best')
plt.show()

plt.figure(figsize=(10, 5))

df = 5
quiquadrado = np.random.chisquare(df, 1000)
sns.distplot(quiquadrado, color='green', label='df=5', hist=False)

df = 10
quiquadrado = np.random.chisquare(df, 1000)
sns.distplot(quiquadrado, color='red', label='df=10', hist=False)

df = 15
quiquadrado = np.random.chisquare(df, 1000)
sns.distplot(quiquadrado, color='blue', label='df=15', hist=False)

plt.title('Chi-Square Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Random Variable')
plt.ylabel('Probability')
plt.legend(loc='best')
plt.show()

plt.figure(figsize=(10, 5))

df = 1000
cauchy = np.random.standard_cauchy(df)
sns.distplot(cauchy, color='green', hist=False)


plt.title('Cauchy Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Random Variable')
plt.ylabel('Probability')
plt.show()

plt.figure(figsize=(10, 5))

alpha, beta = 0, 1
gaussian = np.random.normal(alpha, beta, 1000)
sns.distplot(gaussian, color='green', label='alpha=0, beta=1', hist=False)

alpha, beta = 2, 1
gaussian = np.random.normal(alpha, beta, 1000)
sns.distplot(gaussian, color='red', label='alpha=1, beta=1', hist=False)

alpha, beta = 2, 3
gaussian = np.random.normal(alpha, beta, 1000)
sns.distplot(gaussian, color='blue', label='alpha=2, beta=3', hist=False)

plt.title('Gaussian Distribution (N=1000)', fontdict={'fontsize': 20})
plt.xlabel('Random Variable')
plt.ylabel('Probability')
plt.legend(loc='best')
plt.show()