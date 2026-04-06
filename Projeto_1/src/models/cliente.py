class Cliente:
    """
    Classe que representa um cliente do sistema bancario.
    responsavel por armazenar dados e reaalizar operações financeiras.
    """
    def __init__(self, nome: str, idade: int, saldo: float):
        """
        Inicializa um novo cliente.
        :param nome: Nome do cliente
        :param idade: Idade do cliente
        :param saldo: Saldo do cliente
        """
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo
        self.__ativo = True

    @property
    def nome(self):
        """
        retorna o nome do cliente
        """
        return self.__nome

    @property
    def idade(self):
        """
        retorna a idade do cliente
        """
        return self.__idade

    @property
    def saldo(self):
        """
        retorna o saldo do cliente
        """
        return self.__saldo

    @property
    def ativo(self):
        """
        retorna o status da conta
        """
        return self.__ativo

    def depositar(self, valor: float):
        """
        realiza um depósito na conta.
        :param valor: valor a ser depositado.
        """
        if valor > 0:
            self.__saldo += valor
            print(f"Depósito de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")
        else:
            print("Erro: valor inválido para depósito.")

    def sacar(self, valor: float):
        """
        realiza um saque com validação de saldo.
        :param valor: valor a ser sacado
        """
        if valor <= 0:
            print("Erro: valor inválido.")
            return

        if valor > self.__saldo:
            print("Erro: saldo insuficiente. Operação cancelada.")
        else:
            self.__saldo -= valor
            print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")

    def exibir_dados(self):
        """
        exibe os dados do cliente
        """
        print(f"Nome: {self.__nome} | Idade: {self.__idade} | Saldo: R${self.__saldo:.2f} | Ativo: {self.__ativo}")