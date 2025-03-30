class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.__cpf = cpf  # Encapsulamento

    def exibir_informacoes(self):
        return f"Nome: {self.nome}, CPF: {self.__cpf}"

    def get_cpf(self):
        return self.__cpf
