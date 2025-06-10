# Teste da classe Cliente
from cliente.py import Cliente
    # Criando uma instância de Cliente
    cliente1 = Cliente("João Silva", 30, 1000.0)
    
    # Exibindo informações iniciais
    cliente1.mostrar_informacoes()
    
    # Atualizando o saldo
    cliente1.atualizar_saldo(500.0)
    
    # Exibindo informações após atualização
    cliente1.mostrar_informacoes()
