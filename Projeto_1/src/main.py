"""Script principal para testar a classe Cliente"""

from models.cliente import Cliente

def exibir_relatorio(clientes):
    print("--- RELATÓRIO GERAL ---")
    for i, cliente in enumerate(clientes):
        print(f"ID: {i} | Nome: {cliente.nome} | Idade: {cliente.idade} | "
              f"Saldo: R${cliente.saldo:.2f} | Ativo: {cliente.ativo}")

if __name__ == "__main__":
    clientes = [
        Cliente("João Silva", 30, 1000.0),
        Cliente("Maria Souza", 25, 500.0)
    ]

    clientes[0].sacar(1500.0)  # Não permite saldo negativo
    clientes[0].depositar(200.0)
    clientes[1].sacar(100.0)

    exibir_relatorio(clientes)










    