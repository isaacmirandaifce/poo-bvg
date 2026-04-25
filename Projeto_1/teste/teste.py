import sys
import pathlib

# coloca a pasta raiz do projeto no sys.path
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[1]))

from src.cliente import Cliente

cliente1 = Cliente("João Silva", 30, 1000.0)
cliente1.mostrar_informacoes()

cliente1.atualizar_saldo(500.0)
cliente1.mostrar_informacoes()

# Exemplo extra: desconto
cliente1.atualizar_saldo(-200.0)
cliente1.mostrar_informacoes()






