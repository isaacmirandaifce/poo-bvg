class Cliente:
    def __init__(self, nome: str, cpf: str):
        self.__nome = nome
        self.__cpf = cpf

    def exibir_informacoes(self):
        informacoes = (
            f"Informações do Cliente:\n"
            f"Nome: {self.__nome}\n"
            f"cpf: {self.__cpf}\n"
        )
        return informacoes

    def __repr__(self):
        return f"Cliente(nome='{self.__nome}', cpf='{self.__cpf}')"
