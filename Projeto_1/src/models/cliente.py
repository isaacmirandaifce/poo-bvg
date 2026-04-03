"""Modelagem da entidade Cliente para o sistema bancário"""

class Cliente:
    """Classe que representa um cliente no sistema bancário."""

    def __init__(self, nome: str, idade: int, saldo_inicial: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__ativo = True

    # Getters
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

    # Métodos
    def sacar(self, valor: float):
        if not self.__ativo:
            print(f"Erro: Conta de {self.__nome} está inativa.")
            return
        if valor > self.__saldo:
            print(f"Erro: Saldo insuficiente para saque de R${valor:.2f}.")
            return
        self.__saldo -= valor
        print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")

    def depositar(self, valor: float):
        if not self.__ativo:
            print(f"Erro: Conta de {self.__nome} está inativa.")
            return
        self.__saldo += valor
        print(f"Depósito de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")

    def desativar_conta(self):
        self.__ativo = False



        