import sys
sys.path.insert(1, '/workspaces/poo-bvg/Projeto_1/Projeto_1 - Tainá Rodrigues/')
import src.cliente

from src.cliente import Cliente

#teste da classe (saber se deu certo)

cliente1 = Cliente("João Silva", 30, 1000.0)
cliente1.mostrar_informacoes()
cliente1.atualizar_saldo(500.0)
cliente1.mostrar_informacoes()