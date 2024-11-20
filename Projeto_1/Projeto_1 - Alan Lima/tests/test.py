import sys
import os

# Adiciona a pasta "src" ao caminho de busca do Python
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

from Cliente import Cliente

# Testando a classe Cliente
cliente = Cliente('Alan', 20, 1412)
cliente.mostrar_informacoes()
cliente.atualizar_saldo(500)  
cliente.mostrar_informacoes()
