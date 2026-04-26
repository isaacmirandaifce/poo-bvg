class Cliente:
    def __init__(self,nome: str, cpf: int):
        self.__nomeCliente = nome
        self.__cpfCliente = cpf

    @property
    def nome(self) -> str:
        return self.__nomeCliente