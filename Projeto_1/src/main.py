"""
Script principal de inicialização e teste do sistema bancário refatorado.
Demonstra o funcionamento da classe Cliente e valida os critérios de
aceitação do Ticket #402, incluindo a correção do bug de saldo negativo.
"""

from models.Cliente import Cliente


def exibir_relatorio(clientes: list[Cliente]) -> None:
    """
    Exibe um relatório geral de todos os clientes cadastrados.

    Args:
        clientes (list[Cliente]): Lista de objetos Cliente a serem exibidos.
    """
    print("\n" + "=" * 65)
    print("          RELATÓRIO GERAL DE CLIENTES")
    print("=" * 65)
    for i, cliente in enumerate(clientes):
        print(f"ID: {i:02d} | ", end="")
        cliente.exibir_dados()
    print("=" * 65 + "\n")


def main() -> None:
    """
    Função principal que orquestra a demonstração do sistema refatorado.

    Cobre os seguintes cenários:
        1. Cadastro de clientes via instanciação da classe.
        2. Depósito e saque bem-sucedidos.
        3. Tentativa de saque com saldo insuficiente (bug corrigido).
        4. Operação em conta inativa.
        5. Validação de dados inválidos na criação do cliente.
    """

    print("\n SISTEMA BANCÁRIO — (Refatorado)\n")

    # Cadastro de clientes (substitui as listas paralelas globais)
    print("--- Cadastrando clientes ---")
    joao = Cliente("João Silva", 30, 1000.0)
    maria = Cliente("Maria Souza", 25, 500.0)
    print(f"Cliente criado: {joao}")
    print(f"Cliente criado: {maria}\n")

    clientes = [joao, maria]
    
    # Operações válidas
    print("--- Operações válidas ---")
    joao.depositar(200.0)
    maria.depositar(100.0)
    maria.sacar(50.0)

    # Tentativa de saque com saldo insuficiente (corrigido)
    print("\n--- Tentativa de saque com saldo insuficiente (bug corrigido) ---")
    try:
        joao.sacar(2000.0)  # João tem R$1200.00; operação deve ser recusada
    except ValueError as e:
        print(f"[RECUSADO] {e}")

    # Desativação de conta e tentativa de movimentação
    print("\n--- Desativando conta e tentando movimentar ---")
    maria.desativar_conta()
    try:
        maria.depositar(100.0)
    except RuntimeError as e:
        print(f"[RECUSADO] {e}")

    # Validação de dados inválidos na criação
    print("\n--- Tentativa de criar cliente com dados inválidos ---")
    try:
        cliente_invalido = Cliente("", 25, 100.0)
    except ValueError as e:
        print(f"[RECUSADO] Criação inválida: {e}")

    try:
        cliente_invalido = Cliente("Carlos", 30, -50.0) 
    except ValueError as e:
        print(f"[RECUSADO] Criação inválida: {e}")
        
    # relatório
    exibir_relatorio(clientes)

if __name__ == "__main__":
    main()