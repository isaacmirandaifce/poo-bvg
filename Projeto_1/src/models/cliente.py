class Cliente:
    """Representa um cliente do Core Bancário.

    Os atributos são privados; o acesso de leitura é feito por properties
    e o saldo só é alterado pelos métodos depositar() e sacar().
    """

    def __init__(self, nome, idade, saldo_inicial=0.0):
        """Cria um cliente ativo.

        Args:
            nome (str): Nome do cliente.
            idade (int): Idade do cliente.
            saldo_inicial (float): Saldo de abertura (não pode ser negativo).

        Raises:
            ValueError: Se o saldo inicial for negativo.
        """
        if saldo_inicial < 0:
            raise ValueError("O saldo inicial não pode ser negativo.")
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__status = True

    @property
    def nome(self):
        """str: Nome do cliente (somente leitura)."""
        return self.__nome

    @property
    def idade(self):
        """int: Idade do cliente (somente leitura)."""
        return self.__idade

    @property
    def saldo(self):
        """float: Saldo atual (somente leitura)."""
        return self.__saldo

    @property
    def status(self):
        """bool: True se a conta está ativa (somente leitura)."""
        return self.__status

    def depositar(self, valor):
        """Adiciona um valor ao saldo.

        Args:
            valor (float): Valor a depositar (deve ser positivo).

        Raises:
            ValueError: Se a conta estiver inativa ou o valor for inválido.
        """
        if not self.__status:
            raise ValueError("Conta inativa.")
        if valor <= 0:
            raise ValueError("O valor do depósito deve ser positivo.")
        self.__saldo += valor

    def sacar(self, valor):
        """Retira um valor do saldo, impedindo saldo negativo.

        Args:
            valor (float): Valor a sacar (deve ser positivo).

        Raises:
            ValueError: Se a conta estiver inativa, o valor for inválido
                ou o saldo for insuficiente.
        """
        if not self.__status:
            raise ValueError("Conta inativa.")
        if valor <= 0:
            raise ValueError("O valor do saque deve ser positivo.")
        if valor > self.__saldo:
            raise ValueError(
                f"Saldo insuficiente. Saldo atual: R${self.__saldo:.2f}"
            )
        self.__saldo -= valor

    def desativar(self):
        """Marca a conta como inativa."""
        self.__status = False

    def __str__(self):
        """Retorna uma linha de resumo do cliente para relatórios."""
        ativo = "Sim" if self.__status else "Não"
        return (f"Nome: {self.__nome} | Idade: {self.__idade} | "
                f"Saldo: R${self.__saldo:.2f} | Ativo: {ativo}")