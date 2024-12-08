class Modelo:
    def __init__(self, nome: str):
        self.__nome = nome

    def __repr__(self):
        return f"Modelo(nome='{self.__nome}')"
