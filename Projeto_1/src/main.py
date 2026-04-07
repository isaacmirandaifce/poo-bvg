from models.cliente import Cliente

def main():
    """
    Simula o uso do sistema de clientes.
    Cria clientes, realiza operações e mostra um relatório final.
    """

    clientes = []

    # Cadastro
    clientes.append(Cliente("Davi Maciel", 30, 1000.0))
    clientes.append(Cliente("Nágilla Silva", 25, 500.0))

    # Operações
    clientes[0].sacar(1500.0)
    clientes[0].depositar(200.0)
    clientes[1].sacar(100.0)

    # Testes
    clientes[1].desativar()
    clientes[1].depositar(50) 

    clientes[0].depositar(-10)
    clientes[0].sacar(0)      

    # Relatório
    print("\n--- RELATÓRIO GERAL ---")
    for i, cliente in enumerate(clientes):
        cliente.exibir_dados(i)


if __name__ == "__main__":
    main()