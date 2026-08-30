class Cliente:
    """
    Classe responsável por representar um cliente no sistema do core bancário.
    Centraliza os dados e as regras de negócio associadas à conta de um cliente,
    garantindo o encapsulamento e a segurança das operações financeiras.
    """

    def __init__(self, id_cliente: int, nome: str, idade: int, saldo_inicial: float):
        """
        Inicializa um novo cliente com os atributos estritamente privados.
        
        Args:
            id_cliente (int): O identificador único do cliente.
            nome (str): O nome completo do cliente.
            idade (int): A idade do cliente.
            saldo_inicial (float): O saldo inicial da conta.
        """
        self.__id_cliente = id_cliente
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__status_ativo = True

    @property
    def id_cliente(self) -> int:
        """Retorna o ID do cliente."""
        return self.__id_cliente

    @property
    def nome(self) -> str:
        """Retorna o nome do cliente."""
        return self.__nome

    @property
    def idade(self) -> int:
        """Retorna a idade do cliente."""
        return self.__idade

    @property
    def saldo(self) -> float:
        """Retorna o saldo atual do cliente."""
        return self.__saldo

    @property
    def status_ativo(self) -> bool:
        """Retorna o status de atividade da conta."""
        return self.__status_ativo

    def depositar(self, valor: float):
        """
        Realiza um depósito na conta do cliente.

        Args:
            valor (float): O valor a ser depositado.

        Raises:
            ValueError: Se o valor do depósito for negativo ou zero, ou se a conta estiver inativa.
        """
        if not self.__status_ativo:
            raise ValueError("Operação negada: Conta inativa.")
        if valor <= 0:
            raise ValueError("O valor de depósito deve ser positivo.")
        
        self.__saldo += valor
        print(f"Depósito de R${valor:.2f} realizado na conta de {self.__nome}. Novo saldo: R${self.__saldo:.2f}")

    def sacar(self, valor: float):
        """
        Realiza um saque na conta do cliente, com validação de saldo disponível.

        Args:
            valor (float): O valor a ser sacado.

        Raises:
            ValueError: Se o valor exceder o saldo disponível, for negativo/zero, ou se a conta estiver inativa.
        """
        if not self.__status_ativo:
            raise ValueError("Operação negada: Conta inativa.")
        if valor <= 0:
            raise ValueError("O valor de saque deve ser positivo.")
        if valor > self.__saldo:
            raise ValueError(f"Saldo insuficiente. Saldo atual: R${self.__saldo:.2f}, Tentativa de saque: R${valor:.2f}")
        
        self.__saldo -= valor
        print(f"Saque de R${valor:.2f} realizado na conta de {self.__nome}. Novo saldo: R${self.__saldo:.2f}")

    def desativar_conta(self):
        """Desativa a conta do cliente."""
        self.__status_ativo = False
        print(f"Conta do cliente {self.__nome} foi desativada.")

    def __str__(self) -> str:
        """Retorna uma representação em string dos dados do cliente para relatórios."""
        return (f"ID: {self.__id_cliente} | Nome: {self.__nome} | Idade: {self.__idade} | "
                f"Saldo: R${self.__saldo:.2f} | Ativo: {self.__status_ativo}")