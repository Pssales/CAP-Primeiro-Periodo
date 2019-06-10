# -*- coding: utf-8 -*-
import numpy as np
import pylab
import seaborn as sns

def fatorial(n):
    if(n<=1):
        return 1
    else:
        return (n * fatorial(n-1))


def geraProbabilidades(n, p):
    probabilidades = np.zeros(n+1)
    
    q = 1 - p
    for numP in range(0, n + 1):
        numQ = n - numP
        
        combinacao_n_numP = fatorial(n) / (fatorial(numP) * fatorial(n - numP))
        probabilidades[numP] = combinacao_n_numP * np.power(p, numP) * np.power(q, numQ) # Probabilidade Binomial
    
    return probabilidades


def plot(probabilidades, n):
    bins = np.arange(0, n+1, 1)
    
    # Set a new plot
    pylab.plt.subplots()
    pylab.clf()    
    pylab.plt.bar(bins, probabilidades, color='red', ec='0.4', lw=1)
            
    if n <= 10:
        pylab.plt.xticks(np.arange(0, n+1, 1))
    elif n <= 20:
        pylab.plt.xticks(np.arange(0, n+1, 2))
    elif n <= 100:
        pylab.plt.xticks(np.arange(0, n+1, 10))
    else:
        pylab.plt.xticks(np.arange(0, n+1, 20))
    
    title = 'Distribuição da probabilidade de um dado valor\n se um dado for jogado um dado ' + str(n) + ' vezes'
    pylab.plt.title(title)
    pylab.plt.xlabel('Número de sucessos')
    pylab.plt.ylabel('Probabilidade de ocorrência (%)')
    pylab.plt.show()



lances = [3, 50, 100]
p = 1/6 

for n in lances:
    print("Lançamento de ", n, " dados simultâneos...")
    probabilidades = geraProbabilidades(n, p)
    
    plot(probabilidades, n)