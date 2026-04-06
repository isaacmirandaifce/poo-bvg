class  Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo
        self.__ativo = True

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

def sacar(self, valor: float):
    if valor <= 0:
        print("Erro: valor inválido.")
        return

    if valor > self.__saldo:
        print("Erro: saldo insuficiente. Operação cancelada.")
    else:
        self.__saldo -= valor
        print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")


            