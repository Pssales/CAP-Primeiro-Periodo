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
    Prob_Gamma = []
    for i in range(0, n_bins):
        Prob_Gamma.append(counts[i]/n)
    return Prob_Gamma, counts

# filename = '..\s3.txt'
# filename = '..\s7.txt'
filename = '..\s8.txt'
data = np.genfromtxt(filename, delimiter = '\n', dtype = 'float32',filling_values = 0)

Prob_Gamma, counts = SOC(data)

x = np.linspace(1, len(counts), len(counts))

log_Prob = np.log10(Prob_Gamma)
log_counts = np.log10(counts)

p = np.array(Prob_Gamma)
p = p[np.nonzero(p)]
c = counts[np.nonzero(counts)]
log_p = np.log10(p)
log_c = np.log10(c)

a = (log_p[np.argmax(c)] - log_p[np.argmin(c)]) / (np.max(c) - np.min(c))
b = log_Prob[0]
y = b * np.power(10, (a*counts))

plt.clf()
plt.plot(np.log10(counts), y,color='red')

plt.title('Self-Organized Criticality')
plt.plt.xlabel('log(ni)')
plt.plt.ylabel('log(Yi)')
plt.plt.grid()
plt.savefig(filename+'soc.png')
plt.show()