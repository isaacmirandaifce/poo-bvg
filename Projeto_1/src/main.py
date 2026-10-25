"""Script de inicialização: testa a classe Cliente."""
from models.cliente import Cliente


def main():
    """Simula o uso do sistema e demonstra a correção do bug."""
    joao = Cliente("João Silva", 30, 1000.0)
    maria = Cliente("Maria Souza", 25, 500.0)

    # Operação que antes deixava o João com saldo de -500.0
    try:
        joao.sacar(1500.0)
    except ValueError as erro:
        print(f"Transação recusada: {erro}")

    # Um saque válido
    joao.sacar(300.0)

    # Testando o encapsulamento
    try:
        joao.saldo = 999999
    except AttributeError:
        print("Erro: o saldo não pode ser alterado diretamente.")

    # Relatório geral
    print("--- RELATÓRIO GERAL ---")
    clientes = [joao, maria]
    for i, cliente in enumerate(clientes):
        print(f"ID: {i} | {cliente}")


if __name__ == "__main__":
    main()