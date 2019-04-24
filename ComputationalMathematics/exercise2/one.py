import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

# def uniforme(x):

def binomial(x):
    n = 10
    p = 0.3
    binomial = stats.binom.pmf(x, n,p)
    print(binomial)
    plt.plot(x,binomial, "k--")
    plt.show()



def beta(x):
    a= 0.5
    b=0.5
    y = stats.beta.pdf(x,a,b)
    print(y)
    plt.plot(x,y,"k--")
    plt.show()
# def laplace(x):

# def gamma(x):

def exponencial(x):
    lamb = 0.5
    y = lamb * np.exp(-lamb *x)

    plt.plot(x,y, "k--")
    plt.show()
# def qui_quadrado(x):

# def cauchy(x):


def gaussiana(x):
    y = stats.norm.pdf(x,0,1)
    print(y)
    plt.plot(x,y,"k--")
    plt.show()


gaussiana(np.arange(0.01,1,0.01))
beta(np.arange(0.01,1,0.01))
binomial(np.arange(0,21))
exponencial(np.arange(0,15,0.1))
cauchy(np.arange(0,15,0.1))

