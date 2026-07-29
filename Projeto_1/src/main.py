from models.cliente import Cliente

def executar_testes():
    """Script para simular o uso do sistema e validar as regras de negócio."""
    
    print("--- INICIALIZANDO CORE BANCÁRIO ---")
    
    # Criando instâncias (Fim das listas paralelas)
    joao = Cliente("João Silva", 30, 1000.0)
    maria = Cliente("Maria Souza", 25, 500.0)

    # 1. Testando o bug do saldo negativo (deve ser barrado)
    print(f"\nTentativa de saque perigoso (João):")
    joao.sacar(1500.0) 

    # 2. Testando operação válida
    print(f"\nOperação válida (Maria):")
    maria.depositar(200.0)
    maria.sacar(100.0)

    # 3. Exibindo Relatório Geral
    print("\n--- RELATÓRIO GERAL ---")
    print(joao)
    print(maria)

if __name__ == "__main__":
    executar_testes()