from models.cliente import Cliente

def execultar_sistema():
    Cliente1 = Cliente("João Silva", 30, 1000.0)
    Cliente2 = Cliente("Maria Souza", 25, 500.0)

    print("--- SIMULAÇÃO DE OPERAÇÕES ---")

    # Testando o bug do saldo negativo
    print(f"Cliente: {Cliente1.nome} | Saldo Atual: R${Cliente1.saldo:.2f}")
    Cliente1.sacar(1500.0)

    print("\n--- RELATÓRIO FINAL ---")
    print(Cliente1.exibir_dados())
    print(Cliente2.exibir_dados())

if __name__ == "__main__":
    execultar_sistema()