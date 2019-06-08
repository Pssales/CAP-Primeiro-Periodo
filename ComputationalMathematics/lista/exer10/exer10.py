# -*- coding: utf-8 -*-
# http://www.scielo.br/scielo.php?script=sci_arttext&pid=S0103-97332000000100004
import numpy as np
import pylab as plt

def SOC(data, n_bins=50):
    Gamma = []
    n = len(data)
    for i in range(0,n):
        Gamma.append((data[i] - np.mean(data))/np.std(data))

    counts, bins = np.histogram(Gamma, n_bins)
    PGamma = []
    for i in range(0, n_bins):
        PGamma.append(counts[i]/n)
    return PGamma, counts

filename = '..\series\s3.txt'
# filename = '..\series\s7.txt'
# filename = '..\series\s8.txt'
data = np.genfromtxt(filename, delimiter = '\n', dtype = 'float32',filling_values = 0)

PGamma, counts = SOC(data)

x = np.linspace(1, len(counts), len(counts))

log_Prob = np.log10(PGamma)

p = np.array(PGamma)
p = p[np.nonzero(p)]
c = counts[np.nonzero(counts)]
logP = np.log10(p)

a = (logP[np.argmax(c)] - logP[np.argmin(c)]) / (np.max(c) - np.min(c))
y = log_Prob[0] * np.power(10, (a*counts))

plt.clf()
plt.scatter(np.log10(counts), y, marker = "." , color="red")
plt.title('Self-Organized Criticality')
plt.plt.xlabel('log(ni)')
plt.plt.ylabel('log(Yi)')
plt.plt.grid()

# plt.savefig(filename+'soc.png')
plt.show()