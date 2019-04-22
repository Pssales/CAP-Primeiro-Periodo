
a = 1/(1-0.9+0.9/16)
print("a:\n")
print(a)
print("\n")

# (b) Calcule o speedup que seria obtido num sistema com 64 processadores.
b = 1/(1-0.9+0.9/64)
print("b:\n")
print(b)
print("\n")

# (c) Quantas vezes o sistema com 64 processadores é mais rápido que o sistema com
# 16 processadores para este programa?
print("c:\n")
print(b/a)


# (d) Quantos processadores são necessários para executar este programa na metade
# do tempo da execução no sistema com 16 processadores? (Justifique a resposta)
