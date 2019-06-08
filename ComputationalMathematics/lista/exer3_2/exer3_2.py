import numpy as np
import math
import matplotlib.pyplot as plt
import scipy.stats as stats


def create(array, upperLimit, downLimit, amount):
    for i in range(amount):
        rand = round(np.random.uniform(upperLimit,downLimit),2)
        array.append(rand)

irreg_temp = []
esp_temp = []
elip_temp = []

create(irreg_temp, 1.97,1.99, 33)
create(irreg_temp, 1.96,1.98, 103)
create(irreg_temp, 1.92,1.96, 64)

arq = open("teste.csv", "w")

for i in range(len(irreg_temp)):
    arq.write(str(irreg_temp[i])+";\n")

arq.close()
print(irreg_temp)