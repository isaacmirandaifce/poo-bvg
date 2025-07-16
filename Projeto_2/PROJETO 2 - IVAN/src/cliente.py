class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.__cpf = cpf

    def get_cpf(self):
        return self.__cpf

    def exibir_informacoes(self):
        print(f"Cliente: {self.nome}, CPF: {self.__cpf}")