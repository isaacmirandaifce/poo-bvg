from models.cliente import Cliente

def main():
    print("--- INICIANDO SISTEMA BANCÁRIO (REFACTOR POO) ---")
    
    # 1. Substituição de variáveis globais e listas paralelas por uma lista de objetos Cliente
    clientes = []

    # Cadastrando clientes
    cliente1 = Cliente(id_cliente=0, nome="João Silva", idade=30, saldo_inicial=1000.0)
    cliente2 = Cliente(id_cliente=1, nome="Maria Souza", idade=25, saldo_inicial=500.0)
    
    clientes.append(cliente1)
    clientes.append(cliente2)
    print("Clientes cadastrados com sucesso!\n")

    # 2. Testando a regra de negócio (Bloqueio de saldo negativo)
    print("--- TESTANDO OPERAÇÕES ---")
    
    try:
        # Operação perigosa do sistema antigo: Tentativa de sacar mais do que tem (1500 contra 1000 de saldo)
        print("Tentando sacar R$1500.00 da conta do João Silva...")
        cliente1.sacar(1500.0) 
    except ValueError as e:
        print(f"ERRO TRATADO: {e}")

    # Operações válidas
    try:
        print("\nRealizando operações regulares...")
        cliente1.depositar(250.0)
        cliente2.sacar(150.0)
    except ValueError as e:
        print(f"ERRO TRATADO: {e}")

    # 3. Exibindo Relatório Final utilizando o método mágico __str__ encapsulado na classe
    print("\n--- RELATÓRIO GERAL ---")
    for cliente in clientes:
        print(cliente)

if __name__ == "__main__":
    main()