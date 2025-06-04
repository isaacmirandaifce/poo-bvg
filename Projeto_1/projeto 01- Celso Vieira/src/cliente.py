class Cliente:
    def __init__(self, nome, idade, saldo):
        """
        Construtor da classe Cliente.
        :param nome: str - Nome do cliente
        :param idade: int - Idade do cliente
        :param saldo: float - Saldo inicial do cliente
        """
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_informacoes(self):
        """Exibe as informações do cliente."""
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo:.2f}")

    def atualizar_saldo(self, valor):
        """
        Atualiza o saldo do cliente.
        :param valor: float - Valor a ser somado ao saldo
        """
        self.__saldo += valor
