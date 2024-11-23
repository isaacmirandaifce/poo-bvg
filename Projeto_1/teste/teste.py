import sys
import os


sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

from cliente import Cliente

cli1 = Cliente (nome= "João Silva", idade= 30, saldo= 1000.0)
cli1.mostrar_informacoes ()
cli1.att_saldo (500.0)
cli1.mostrar_informacoes () 