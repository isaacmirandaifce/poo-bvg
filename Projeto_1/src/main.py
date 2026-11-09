from models.cliente import Cliente

if __name__ == "__main__":
    
    print(f"--- Sistema Bancário ---")
    
    print("\n--- Cadastros de Clientes ---")
    joao = Cliente("João da Silva", 30, 1000.0)
    maria = Cliente("Maria Souza", 25, 500.0)

    print("\n--- Testes ---")
    print("1 - Testando a correção do Bug...")
    print(f"Saldo inicial do {joao.nome}: R${joao.saldo:.2f}")
    try:
        joao.sacar(1500)
    except ValueError as erro:
        print(f"Operação recusada: {erro}")
        print(f"Saldo atualizado de João após a tentativa: R${joao.saldo:.2f}")

    print(f"\n2 - Tentativa de depósito de R$ 200.00 na conta de {maria.nome}...")
    print(f"Saldo inicial de {maria.nome}: R${maria.saldo:.2f}")
    try:
            maria.depositar(200)
    except ValueError as erro:
            print(f"AVISO DO SISTEMA: {erro}")


    print("\n--- RELATÓRIO GERAL ---")
    clientes = [joao, maria]

    for i, cliente in enumerate(clientes):
        print(f"ID: {i} | Nome: {cliente.nome} | Idade: {cliente.idade} | Saldo: R${cliente.saldo:.2f} | Ativo: {cliente.status_ativo}")