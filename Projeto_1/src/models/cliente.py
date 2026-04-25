class Cliente:
    """
    Classe que representa um cliente bancário.

    Responsável por armazenar dados e realizar operações
    de depósito e saque com regras de negócio.
    """

    def __init__(self, nome: str, idade: int, saldo_inicial: float):
        """
        Inicializa um cliente.

        :param nome: Nome do cliente
        :param idade: Idade do cliente
        :param saldo_inicial: Saldo inicial da conta
        """
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__ativo = True

    # Getters usando @property
    @property
    def nome(self):
        return self.__nome

    @property
    def idade(self):
        return self.__idade

    @property
    def saldo(self):
        return self.__saldo

    @property
    def ativo(self):
        return self.__ativo

    def depositar(self, valor: float):
        """
        Realiza um depósito na conta.

        :param valor: Valor a ser depositado
        """
        if valor > 0:
            self.__saldo += valor
            print(f"Depósito de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")
        else:
            print("Erro: Valor inválido para depósito.")

    def sacar(self, valor: float):
        """
        Realiza um saque na conta, impedindo saldo negativo.

        :param valor: Valor a ser sacado
        """
        if valor <= 0:
            print("Erro: Valor inválido.")
            return

        if valor > self.__saldo:
            print("Erro: Saldo insuficiente. Operação cancelada.")
        else:
            self.__saldo -= valor
            print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")

    def desativar_conta(self):
        """
        Desativa a conta do cliente.
        """
        self.__ativo = False

    def exibir_dados(self, id_cliente: int):
        """
        Exibe os dados do cliente.

        :param id_cliente: ID do cliente
        """
        print(f"ID: {id_cliente} | Nome: {self.__nome} | Idade: {self.__idade} | Saldo: R${self.__saldo:.2f} | Ativo: {self.__ativo}")