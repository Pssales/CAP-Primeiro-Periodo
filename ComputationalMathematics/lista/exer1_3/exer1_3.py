import numpy as np

def standardize(signal):
    return (signal - np.mean(signal))/np.std(signal)

def soma(s1, s2):
    S1 = np.genfromtxt(s1,delimiter = ',',dtype = 'float32',filling_values = 0) 
    S2 = np.genfromtxt(s2,delimiter = ',',dtype = 'float32',filling_values = 0) 

    sr = standardize(S1 + S2)
    return sr

S5 = soma('..\series\S1.txt', '..\series\S4.txt')
S6 = soma('..\series\S2.txt', '..\series\S4.txt')
S7 = soma('..\series\S3.txt', '..\series\S4.txt')





