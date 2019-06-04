import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
# import seaborn

# Normaliza o sinal entre -1 e 1
def normalize(signal):
    return ((signal - min(signal))/(max(signal) - min(signal)) - 0.5) * 2

def plot(filename):
    data = np.genfromtxt(filename,delimiter = ',',dtype = 'float32',filling_values = 0) 
    # sns.distplot(data)
    data = normalize(data)
    plt.plot(data, color='red')
    plt.xlabel('t')
    plt.ylabel('A(t)')
    plt.savefig(filename+'.png')
    plt.show()
    
   
# plot("s1.txt")
# plot("s2.txt")
# plot("s3.txt")
# plot("s4.txt")
# plot("s5.txt")
# plot("s6.txt")
# plot("s7.txt")
plot("s8.txt")
plot("s9.txt")
plot("s10.txt")

# plot("snorms1.txt")
# plot("snorms2.txt")
# plot("snorms3.txt")