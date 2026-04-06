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



            