# Código de teste da classe Cliente
from src.cliente import Cliente
import sys
sys.path.append("cliente")
if __name__ == "__main__":
    # Criação de uma instância da classe Cliente com nome, idade e saldo inicial
    cliente1 = Cliente("João Silva", 30, 1000.0)
    
    # Exibe as informações do cliente antes da atualização de saldo
    cliente1.mostrar_informacoes()
    
    # Atualiza o saldo do cliente somando 500.0 ao saldo atual
    cliente1.atualizar_saldo(500.0)
    
    # Exibe as informações do cliente após a atualização do saldo
    cliente1.mostrar_informacoes()
