import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')
from classeCliente import Cliente


# Testando diferentes casos
cliente1 = Cliente("Larissa Vieira", "000.111.222-33")
print(cliente1.exibir_informacoes())
print(repr(cliente1))

cliente2 = Cliente("Mark Zuckerberg", "564.850.357-45")
print(cliente2.exibir_informacoes())
print(repr(cliente2))