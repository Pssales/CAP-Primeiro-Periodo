import colorednoise as cn
samples = 2**12 # number of samples to generate

beta = 0 # the exponent
S1 = cn.powerlaw_psd_gaussian(beta, samples)

beta = 1 # the exponent
S2 = cn.powerlaw_psd_gaussian(beta, samples)

beta = 2 # the exponent
S3 = cn.powerlaw_psd_gaussian(beta, samples)

# optionally plot the Power Spectral Density with Matplotlib
import numpy as np
import numpy as np
import matplotlib.pyplot as plt

#s, f = mlab.psd(y, NFFT=2**13)
#plt.loglog(f,s)
#plt.grid(True)
#plt.show()


x = 10*np.array(range(len(S1)))

# plt.plot( x, S1,  color='gray') # linha pontilha orange

# plt.plot( x, S2,  color='pink')  # linha tracejada azul
plt.plot( x, S3,  color='red')  # linha tracejada azul

plt.title("Mais incrementado")
plt.grid(True)
plt.xlabel("eixo horizontal")
plt.ylabel("que legal")
plt.show()
