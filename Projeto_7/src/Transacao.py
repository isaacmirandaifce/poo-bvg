class Transacao:
    def __init__(self, id_transacao: int, valor: float, tipo: str):
        self.__id = id_transacao
        self.__valor = valor
        self.__tipo = tipo

    def get_valor(self) -> float:
        return self.__valor

    def get_tipo(self) -> str:
        return self.__tipo

    def __str__(self) -> str:
        return f"Transação [ID: {self.__id} | Valor: R${self.__valor:.2f} | Tipo: {self.__tipo}]"