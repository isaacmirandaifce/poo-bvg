# Avisa para o python onde localizar o arquivo do cliente.py:

import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

# Exemplo de uso:

from cliente import Cliente

cli1 = Cliente (nome= "João Silva", idade= 30, saldo= 1000.0)
cli1.mostrar_informacoes ()

# Atualizando o saldo:

cli1.att_saldo (500.0)
cli1.mostrar_informacoes () 
