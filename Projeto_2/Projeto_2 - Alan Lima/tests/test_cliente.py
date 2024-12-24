import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')
from cliente import Cliente


# Testando diferentes casos
cliente1 = Cliente("Maria Oliveira", "987.654.321-00")
print(cliente1.exibir_informacoes())
print(repr(cliente1))

cliente2 = Cliente("Carlos Pereira", "111.222.333-44")
print(cliente2.exibir_informacoes())
print(repr(cliente2))
