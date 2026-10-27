class Cliente:
    """ Cria um objeto Cliente com seus dados pessoais e financeiros,
    onde todos os atributos são privados e podem ser consultados por meio
    de propriedades. As operações financeiras são realizadas pelos
    métodos da própria classe.

    Args:
        nome (str): Nome do cliente.
        idade (int): Idade do cliente.
        saldo_inicial (float): Saldo inicial da conta.
        ativo (bool): Indica se a conta está ativa, onde o padrão é True.

    Raises:
        ValueError: Se a idade ou o saldo inicial forem negativos. """
    def __init__(self, nome, idade, saldo_inicial, ativo = True):
        self.__nome = nome
        self.__idade = idade
        self.__saldo_inicial = saldo_inicial
        self.__ativo = ativo

@property
def nome(self):
        """Retorna o nome do cliente.
        Returns:
            str: Nome armazenado no objeto."""
        return self.__nome

@property
def idade(self):
        """Retorna a idade do cliente.
        Returns:
            int: Idade armazenada no objeto. """
        return self.__idade

@property
def saldo(self):
        """Retorna o saldo atual da conta.
        Returns:
            float: Saldo atual do cliente."""
        return self.__saldo

@property
def status(self):
        """ Retorna o estado atual da conta.
        Returns:
            bool: True se a conta estiver ativa; False caso contrário. """
        return self.__status

def cadastrar_cliente(lista_clientes, limite_clientes=100):
    """ Solicita os dados de novos clientes e cadastra seus objetos.

        Args:
            lista_clientes (list): Lista de objetos Cliente cadastrados.
            limite_clientes (int): Número máximo de clientes permitidos.

        Returns:
            None: Encerra o cadastro quando o usuário digita 'sair'
            ou quando o limite de clientes é atingido.
        """
    print('Bem-vindo ao sistema de cadastro de clientes')
    while True:
        if len(lista_clientes) >= limite_clientes:
            print("Erro Crítico: Limite de memória atingido.")
            break

        vagas_clientes = limite_clientes - len(lista_clientes)
        print(f"\n[Status: {len(lista_clientes)}/{limite_clientes} clientes - {vagas_clientes} vagas restantes]")

        nome_cliente = input('Digite o nome do cliente (ou então digite "sair" para encerrar a sessão e exibir todos os clientes cadastrados): ')
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

        novo_cliente = Cliente(nome_cliente, idade_cliente, saldo_cliente, ativo=status_ativo)
        lista_clientes.append(novo_cliente)
        print(f"Cliente {nome_cliente} cadastrado(a) com sucesso! O seu ID é {len(lista_clientes) - 1}")

def obter_cliente_ativo(lista_clientes, id_cliente):
    """Localiza um cliente pelo ID e verifica se sua conta está ativa.

       Args:
           lista_clientes (list): Lista de objetos Cliente.
           id_cliente (int): Índice do cliente na lista.

       Returns:
           Cliente | None: O objeto encontrado ou None se o ID for inválido
           ou se a conta estiver inativa."""
    if not (0 <= id_cliente < len(lista_clientes)):
        print(f"ERRO! Cliente com ID {id_cliente} não encontrado!")
        return None

    cliente = lista_clientes[id_cliente]

    if not cliente.ativo:
        print(f"ERRO! A conta do cliente {cliente.nome} está inativa!")
        return None
    return cliente

def sacar(lista_clientes, id_cliente, valor):
    """Realiza um saque da conta, desde que haja saldo suficiente.
    
        Args:
            valor (float): Valor que será retirado da conta.

        Returns:
            bool: True se o saque for realizado.

        Raises:
            ValueError: Se a conta estiver inativa, o valor for inválido
                        ou não houver saldo suficiente."""
    cliente = obter_cliente_ativo(lista_clientes, id_cliente)
    if cliente is None:
        return False
    if valor <= 0:
        print("ERRO! O valor do saque deve ser maior que zero!")
        return False
    if valor > cliente.saldo_inicial:
        print(f"ERRO! Saldo insuficiente. Saldo atual: R$ {cliente.saldo_inicial:.2f}")
        return False

    cliente.saldo_inicial -= valor
    print(f"Saque de R$ {valor:.2f} realizado. Novo saldo de {cliente.nome}: R$ {cliente.saldo_inicial:.2f}")
    return True

def depositar(lista_clientes, id_cliente, valor):
    """Adiciona um valor positivo ao saldo da conta.

        Args:
            valor (float): Valor que será depositado.

        Returns:
            bool: True se o depósito for realizado.

        Raises:
            ValueError: Se a conta estiver inativa ou o valor for inválido."""

    cliente = obter_cliente_ativo(lista_clientes, id_cliente)
    if cliente is None:
        return False
    if valor <= 0:
        print("ERRO! O valor do depósito deve ser maior que zero!")
        return False

    cliente.saldo_inicial += valor
    print(f"Depósito de R$ {valor:.2f} realizado. Novo saldo de {cliente.nome}: R$ {cliente.saldo_inicial:.2f}")
    return True

def transferir(lista_clientes, id_origem, id_destino, valor):
    """ Transfere dinheiro da conta atual para outra conta ativa.

        Args:
            destino (Cliente): Objeto Cliente que receberá o dinheiro.
            valor (float): Valor que será transferido.

        Returns:
            bool: True se a transferência for realizada.

        Raises:
            ValueError: Se as contas forem inválidas, estiverem inativas,
                        o valor for inválido ou o saldo for insuficiente."""
    if id_origem == id_destino:
        print("ERRO! A conta de origem e a de destino devem ser diferentes!")
        return False

    origem = obter_cliente_ativo(lista_clientes, id_origem)
    destino = obter_cliente_ativo(lista_clientes, id_destino)
    if origem is None or destino is None:
        return False
    if valor <= 0:
        print("ERRO! O valor da transferência deve ser maior que zero!")
        return False
    if valor > origem.saldo_inicial:
        print(f"ERRO! Saldo insuficiente. Saldo atual de {origem.nome}: R$ {origem.saldo_inicial:.2f}")
        return False

    origem.saldo_inicial -= valor
    destino.saldo_inicial += valor
    print(f"Transferência de R$ {valor:.2f} de {origem.nome} para {destino.nome} realizada.")
    print(f"Saldo de {origem.nome}: R$ {origem.saldo_inicial:.2f} | Saldo de {destino.nome}: R$ {destino.saldo_inicial:.2f}")
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
        status = "Ativo" if cliente.ativo else "Inativo"
        print(f"{id_cliente:<5}{cliente.nome:<22}{cliente.idade:<8}{cliente.saldo_inicial:>14.2f}  {status:<8}")

    print("-" * 62)

    total_clientes = len(lista_clientes)
    contas_ativas = sum(1 for c in lista_clientes if c.ativo)
    saldo_total = sum(c.saldo_inicial for c in lista_clientes)
    saldo_ativos = sum(c.saldo_inicial for c in lista_clientes if c.ativo)

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