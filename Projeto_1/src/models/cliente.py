class  Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo
        self.__ativo = True