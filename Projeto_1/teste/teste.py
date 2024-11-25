import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))

from cliente import Cliente

cliente = Cliente('João', 30, 1200)

cliente.mostrar_informacoes()

cliente.atualizar_saldo(500)
cliente.mostrar_informacoes()
