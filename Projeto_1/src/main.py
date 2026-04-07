from models.cliente import Cliente

def main():
    clientes = []

    # Cadastro
    clientes.append(Cliente("João Silva", 30, 1000.0))
    clientes.append(Cliente("Maria Souza", 25, 500.0))

    # Testes
    clientes[0].sacar(1500.0)  # Agora NÃO deixa saldo negativo
    clientes[1].depositar(200.0)

    # Relatório
    print("\n--- RELATÓRIO GERAL ---")
    for i, cliente in enumerate(clientes):
        cliente.exibir_dados(i)

if __name__ == "__main__":
    main()