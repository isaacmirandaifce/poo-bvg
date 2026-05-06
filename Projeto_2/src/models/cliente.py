class Cliente:
    def __init__(self, nome: str, cpf: str):
        self.nome = nome
        self.__cpf = cpf  # CPF privado

    def get_cpf(self):
        return self.__cpf  # acesso controlado