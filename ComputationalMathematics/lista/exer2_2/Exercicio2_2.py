import numpy as np
import scipy.stats as st
import matplotlib.pyplot as plt

k=np.arange(0, 100)

data = st.binom.pmf(k, 100, (1.0/6))
plt.bar(k, data, color = "red")
plt.ylabel('Probabilidade')
plt.xlabel('Quantidade de dados')
plt.xlim(0, 35)
plt.show()
