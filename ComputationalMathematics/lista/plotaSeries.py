import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Normaliza o sinal entre -1 e 1
def normalize(signal):
    return ((signal - min(signal))/(max(signal) - min(signal)) - 0.5) * 2

def plot(filename):
    data = np.genfromtxt(filename,delimiter = ',',dtype = 'float32',filling_values = 0) 
    data = normalize(data)
    plt.plot(data, color='red')
    plt.xlabel('t')
    plt.ylabel('A(t)')
    plt.savefig(filename+'.png')
    plt.show()
    
   
plot("..\series\s1.txt")
plot("..\series\s2.txt")
plot("..\series\s3.txt")
plot("..\series\s4.txt")
plot("..\series\s5.txt")
plot("..\series\s6.txt")
plot("..\series\s7.txt")
plot("..\series\s8.txt")
plot("..\series\s9.txt")
plot("..\series\s10.txt")
