class Cliente:
    def __init__(self, nome, cpf):
        self.__nome = nome
        self.__cpf = cpf

    def exibir_informacoes(self):
        return f"Cliente: {self.__nome}, CPF: {self.__cpf}"

    def get_nome(self):
        return self.__nome

    def get_cpf(self):
        return self.__cpf