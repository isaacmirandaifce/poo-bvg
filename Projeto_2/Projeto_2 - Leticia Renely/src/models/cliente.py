class Cliente:

    def __init__(self, nome: str, cpf: str):
        self.__nome = nome
        self.__cpf = cpf

    def get_nome(self) -> str:
        return self.__nome

    def get_cpf(self) -> str:
        return self.__cpf