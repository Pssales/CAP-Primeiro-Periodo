
# 2) Considere a expressão para o speedup vista em aula, SP=1/(1-f+f/P). Plote o speedup
# como função do número de processadores (P), dentro do intervalo 1  P  128,
# supondo que a fração paralelizável (f) de um programa corresponde a:
# (a) 98%

import matplotlib.pyplot

results = []
for i in range(1,129):
    results.append(1/(1-0.98+0.98/i))

matplotlib.pyplot.plot(results)
matplotlib.pyplot.show()
resultsb = []
# (b) 80%
for i in range(1,129):
    resultsb.append(1/(1-0.8+0.8/i))

matplotlib.pyplot.plot(resultsb)
matplotlib.pyplot.show()
