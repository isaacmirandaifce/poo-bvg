class Modelo:
    def __init__(self, nome: str):
        self._nome = nome

    def get_nome(self) -> str:
        return self._nome

    def set_nome(self, novo_nome: str) -> None:
        self._nome = novo_nome

    def __str__(self) -> str:
        return self._nome
