from models.cliente import Cliente


def cadastrar_cliente(lista_clientes, limite_clientes=100):
    """Solicita os dados de novos clientes e cadastra seus objetos.

    Args:
        lista_clientes (list): Lista de objetos Cliente cadastrados.
        limite_clientes (int): Número máximo de clientes permitidos.

    Returns:
        None: Encerra o cadastro quando o usuário digita 'sair'
        ou quando o limite de clientes é atingido."""
    print('Bem-vindo ao sistema de cadastro de clientes')
    while True:
        if len(lista_clientes) >= limite_clientes:
            print("Erro Crítico: Limite de memória atingido.")
            break

        vagas_clientes = limite_clientes - len(lista_clientes)
        print(f"\n[Status: {len(lista_clientes)}/{limite_clientes} clientes - {vagas_clientes} vagas restantes]")

        nome_cliente = input('Digite o nome do cliente (ou então digite "sair" para encerrar o cadastro): ')
        if nome_cliente.lower() == 'sair':
            break
        try:
            idade_cliente = int(input(f'Digite a idade de {nome_cliente}: '))
        except ValueError:
            print('Por favor, digite um número válido para a idade.')
            continue
        try:
            saldo_cliente = float(input(f'Digite o saldo inicial da conta de {nome_cliente}: '))
        except ValueError:
            print('Por favor, digite um valor válido para o saldo.')
            continue
        status_input = input(f"O cliente {nome_cliente} está ativo? (S/N): ").strip().upper()
        status_ativo = status_input == 'S'

        try:
            novo_cliente = Cliente(nome_cliente, idade_cliente, saldo_cliente, status=status_ativo)
        except ValueError as erro:
            print(f"ERRO! {erro}")
            continue

        lista_clientes.append(novo_cliente)
        print(f"Cliente {nome_cliente} cadastrado(a) com sucesso! O seu ID é {len(lista_clientes) - 1}")


def buscar_cliente(lista_clientes, id_cliente):
    """Localiza um cliente pelo ID.

    Args:
        lista_clientes (list): Lista de objetos Cliente.
        id_cliente (int): Índice do cliente na lista.

    Returns:
        Cliente: O objeto encontrado.

    Raises:
        ValueError: Se o ID for inválido."""
    if not (0 <= id_cliente < len(lista_clientes)):
        raise ValueError(f"Cliente com ID {id_cliente} não encontrado!")
    return lista_clientes[id_cliente]


def sacar(lista_clientes, id_cliente, valor):
    """Executa o saque de um cliente e exibe o resultado.

    Args:
        lista_clientes (list): Lista de objetos Cliente.
        id_cliente (int): ID do cliente.
        valor (float): Valor a ser sacado.

    Returns:
        bool: True se o saque foi realizado; False se foi recusado."""
    try:
        cliente = buscar_cliente(lista_clientes, id_cliente)
        cliente.sacar(valor)
    except ValueError as erro:
        print(f"ERRO! {erro}")
        return False

    print(f"Saque de R$ {valor:.2f} realizado. Novo saldo de {cliente.nome}: R$ {cliente.saldo:.2f}")
    return True


def depositar(lista_clientes, id_cliente, valor):
    """Executa o depósito na conta de um cliente e exibe o resultado.

    Args:
        lista_clientes (list): Lista de objetos Cliente.
        id_cliente (int): ID do cliente.
        valor (float): Valor a ser depositado.

    Returns:
        bool: True se o depósito foi realizado; False se foi recusado."""
    try:
        cliente = buscar_cliente(lista_clientes, id_cliente)
        cliente.depositar(valor)
    except ValueError as erro:
        print(f"ERRO! {erro}")
        return False

    print(f"Depósito de R$ {valor:.2f} realizado. Novo saldo de {cliente.nome}: R$ {cliente.saldo:.2f}")
    return True


def transferir(lista_clientes, id_origem, id_destino, valor):
    """Executa a transferência entre duas contas e exibe o resultado.

    Args:
        lista_clientes (list): Lista de objetos Cliente.
        id_origem (int): ID do cliente que envia o dinheiro.
        id_destino (int): ID do cliente que recebe o dinheiro.
        valor (float): Valor a ser transferido.

    Returns:
        bool: True se a transferência foi realizada; False se foi recusada."""
    try:
        origem = buscar_cliente(lista_clientes, id_origem)
        destino = buscar_cliente(lista_clientes, id_destino)
        origem.transferir(destino, valor)
    except ValueError as erro:
        print(f"ERRO! {erro}")
        return False

    print(f"Transferência de R$ {valor:.2f} de {origem.nome} para {destino.nome} realizada.")
    print(f"Saldo de {origem.nome}: R$ {origem.saldo:.2f} | Saldo de {destino.nome}: R$ {destino.saldo:.2f}")
    return True


def menu_movimentacao(lista_clientes):
    """Exibe o menu de movimentações financeiras e processa a opção escolhida.

    Args:
        lista_clientes (list): Lista de objetos Cliente cadastrados.

    Returns:
        None: Retorna ao menu principal após a operação escolhida."""
    print("\n--- MOVIMENTAÇÃO DE CONTA ---")
    print("1 - Saque")
    print("2 - Depósito")
    print("3 - Transferência")
    print("0 - Voltar")
    opcao = input("Escolha uma opção: ").strip()

    if opcao == '0':
        return
    if opcao not in ('1', '2', '3'):
        print("Opção inválida.")
        return
    try:
        if opcao == '3':
            id_origem = int(input("Digite o ID da conta de origem: "))
            id_destino = int(input("Digite o ID da conta de destino: "))
            valor = float(input("Digite o valor da transferência: R$ "))
            transferir(lista_clientes, id_origem, id_destino, valor)
        else:
            id_cliente = int(input("Digite o ID do cliente: "))
            valor = float(input("Digite o valor: R$ "))
            if opcao == '1':
                sacar(lista_clientes, id_cliente, valor)
            else:
                depositar(lista_clientes, id_cliente, valor)
    except ValueError:
        print("Entrada inválida. Digite apenas números.")


def exibir_relatorio(lista_clientes):
    """Exibe os clientes cadastrados e os totais das contas.

    Args:
        lista_clientes (list): Lista de objetos Cliente cadastrados.

    Returns:
        None: Imprime o relatório no terminal."""
    if not lista_clientes:
        print("Nenhum cliente cadastrado dentro do sistema.")
        return

    print("\n" + "=" * 62)
    print("RELATÓRIO GERAL DE CONTAS")
    print("=" * 62)
    print(f"{'ID':<5}{'Nome':<22}{'Idade':<8}{'Saldo (R$)':>14}  {'Status':<8}")
    print("-" * 62)

    for id_cliente, cliente in enumerate(lista_clientes):
        status = "Ativo" if cliente.status else "Inativo"
        print(f"{id_cliente:<5}{cliente.nome:<22}{cliente.idade:<8}{cliente.saldo:>14.2f}  {status:<8}")

    print("-" * 62)

    total_clientes = len(lista_clientes)
    contas_ativas = sum(1 for c in lista_clientes if c.status)
    saldo_total = sum(c.saldo for c in lista_clientes)
    saldo_ativos = sum(c.saldo for c in lista_clientes if c.status)

    print(f"Total de contas: {total_clientes} ({contas_ativas} ativas, {total_clientes - contas_ativas} inativas)")
    print(f"Saldo total (todas as contas): R$ {saldo_total:.2f}")
    print(f"Saldo total (contas ativas):   R$ {saldo_ativos:.2f}")
    print("=" * 62)


def main():
    """Controla a execução do sistema por meio do menu principal.

    Returns:
        None: Encerra o programa quando o usuário escolhe a opção 0."""
    clientes = []

    while True:
        print("\n===== MENU =====")
        print("1 - Cadastrar clientes")
        print("2 - Movimentar conta (saque, depósito, transferência)")
        print("3 - Relatório geral")
        print("0 - Sair")
        opcao = input("Escolha uma opção: ").strip()

        if opcao == '1':
            cadastrar_cliente(clientes)
        elif opcao == '2':
            menu_movimentacao(clientes)
        elif opcao == '3':
            exibir_relatorio(clientes)
        elif opcao == '0':
            print("Encerrando o sistema.")
            break
        else:
            print("Opção inválida.")


if __name__ == "__main__":
    main()