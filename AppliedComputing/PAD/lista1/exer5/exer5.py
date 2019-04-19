#Speedup em escala (Gustafson): S’ = (P-1) f + 1

# 5) Utilizando as mesmas escalas dos gráficos construídos acima em 2-a e em 3-a,
# respectivamente, plote o speedup-em-escala para os seguintes casos:

import matplotlib.pyplot
# (a) f = 98% , 1 <= P <= 128
results = []
for i in range(1,129):
    results.append((i-1)*0.98 + 1)

matplotlib.pyplot.plot(results)
matplotlib.pyplot.show()

# (b) 8 processadores , 0 < f < 1
resultsb = []
for i in range(1,100):
    resultsb.append((8-1)*(i/100) + 1)

matplotlib.pyplot.plot(resultsb)
matplotlib.pyplot.show()