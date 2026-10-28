

class Cliente:
    """Representa um cliente do sistema bancário."""

    def __init__(self, nome, idade, saldo, status):
        """
        Inicializa os dados do cliente.
        Entradas: nome, idade, saldo e status.
        Saída: inicializa os atributos privados.
        """
        if saldo < 0:
            raise ValueError("O saldo inicial não pode ser negativo.")

        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo
        self.__status = status

    @property
    def nome(self):
        """Retorna o nome do cliente."""
        return self.__nome

    @property
    def idade(self):
        """Retorna a idade do cliente."""
        return self.__idade

    @property
    def saldo(self):
        """Retorna o saldo do cliente."""
        return self.__saldo

    @property
    def status(self):
        """Retorna o status da conta."""
        return self.__status

    def depositar(self, valor):
        """
        Realiza depósitos em contas ativas.
        Entrada: valor a depositar.
        Saída: exibe uma mensagem com o resultado.
        """
        if not self.__status:
            print("Erro: Conta inativa.")
        elif valor <= 0:
            print("Erro: Valor inválido.")
        else:
            self.__saldo += valor
            print("Depósito realizado com sucesso!")

    def sacar(self, valor):
        """
        Realiza saques sem permitir saldo negativo.
        Entrada: valor a sacar.
        Saída: exibe uma mensagem com o resultado.
        """
        if not self.__status:
            print("Erro: Conta inativa.")
        elif valor <= 0:
            print("Erro: Valor inválido.")
        elif valor > self.__saldo:
            print("Erro: Saldo insuficiente!")
        else:
            self.__saldo -= valor
            print("Saque realizado com sucesso!")











