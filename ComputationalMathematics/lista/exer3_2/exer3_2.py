import numpy as np
import math
import matplotlib.pyplot as plt
import scipy.stats as stats


def create(array, upperLimit, downLimit, amount):
    for i in range(amount):
        rand = round(np.random.uniform(upperLimit,downLimit),2)
        array.append(rand)

irregular = []
espiral = []
elipitica = []

for i in range(10):
    create(irregular, 1.97,1.99, 33)
    create(espiral, 1.96,1.98, 103)
    create(elipitica, 1.92,1.96, 64)

arqIrre = open("totalirregular.csv", "w")
arqEsp = open("totalespiral.csv", "w")
arqEli = open("totaleliptica.csv", "w")
arqTotal = open("totalcompleto.csv", "w")

for i in range(len(irregular)):
    arqIrre.write(str(irregular[i])+";\n")
    arqTotal.write(str(irregular[i])+";\n")

for i in range(len(espiral)):
    arqEsp.write(str(espiral[i])+";\n")
    arqTotal.write(str(espiral[i])+";\n")

for i in range(len(elipitica)):
    arqEli.write(str(elipitica[i])+";\n")
    arqTotal.write(str(elipitica[i])+";\n")

arqIrre.close()
arqEli.close()
arqEsp.close()
arqTotal.close()
print(irregular)