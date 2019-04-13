import numpy as np
from scipy import stats
import matplotlib.pyplot as plt


def binomial(x):
    n = 10
    p = 0.3
    binomial = stats.binom.pmf(x, n,p)
    print(binomial)
    plt.plot(x,binomial)
    plt.show()


# def uniforme(results):

def beta(x):
    a= 0.5
    b=0.5
    y = stats.beta.pdf(x,a,b)
    print(y)
    plt.plot(x,y)
    plt.show()
# def laplace(results):

# def gamma(results):

# def expoencial(results):

# def qui_quadrado(results):

# def cauchy(results):

def gaussiana(x):
    y = stats.norm.pdf(x,0,1)
    print(y)
    plt.plot(x,y)
    plt.show()


gaussiana(np.arange(0.01,1,0.01))
beta(np.arange(0.01,1,0.01))
binomial(np.arange(0,21))

