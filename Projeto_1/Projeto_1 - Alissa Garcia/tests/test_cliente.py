import sys
sys.path.insert(1, '/workspaces/poo-bvg/Projeto_1/Projeto_1 - Alissa Garcia/')
import src.Cliente

from src.Cliente import Clientes

cliente1 = Clientes("João Silva", 30, 1000.0)
cliente1.mostrar_informacoes()
cliente1.atualizar_saldo(500.0)
cliente1.mostrar_informacoes()
