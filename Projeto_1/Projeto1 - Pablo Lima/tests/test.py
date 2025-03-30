import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

from Cliente import Cliente

# Exemplo de uso da classe Cliente
cliente = Cliente("Pablo Vieira", 20, 1000.0)

# Exibir as informações do cliente
cliente.mostrar_informacoes()

# Atualizar o saldo do cliente
cliente.atualizar_saldo(500.0)

# Exibir novamente as informações do cliente
cliente.mostrar_informacoes()