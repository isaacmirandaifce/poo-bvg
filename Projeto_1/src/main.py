from models.cliente import Cliente


def main():
    cliente1 = Cliente("João Silva", 30, 1000.0)
    cliente2 = Cliente("Maria Souza", 25, 500.0)

    # Testando operações
    cliente1.sacar(1500)  # deve dar erro (saldo insuficiente)
    cliente1.depositar(200)

    cliente2.depositar(300)
    cliente2.sacar(100)

    print("\n--- RELATÓRIO ---")
    cliente1.exibir_dados()
    cliente2.exibir_dados()


if __name__ == "__main__":
    main()