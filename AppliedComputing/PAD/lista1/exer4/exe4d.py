# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt

resultsd = []
for i in numpy.arange(1, 4096, 40):
    resultsd.append(1/(1-0.9)+(0.9/i))
plt.plot(resultsd)
plt.savefig('plot3b.png')
plt.show()