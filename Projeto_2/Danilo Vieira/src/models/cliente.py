
class Cliente:

    def __init__(self, nome: str, cpf: str):
        self.__nome = nome
        self.__cpf = cpf
        self.__seguros = []

    @property
    def nome(self) -> str:
        return self.__nome

    @property
    def cpf(self) -> str:
        return self.__cpf

    @property
    def seguros(self) -> list:
        return self.__seguros.copy()

    def adicionarSeguro(self, seguro) -> None:
        self.__seguros.append(seguro)
