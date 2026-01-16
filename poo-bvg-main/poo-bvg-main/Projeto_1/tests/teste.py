# Teste da classe Cliente
import cliente


if __name__ == "__main__":
    # Criando uma instância de Cliente
    cliente1 = cliente("Joao", 500, 2000.7)
    
    # Exibindo informações iniciais
    cliente1.mostrar_informacoes()
    
    # Atualizando o saldo
    cliente1.atualizar_saldo(750.6)
    
    # Exibindo informações após atualização
    cliente1.mostrar_informacoes()