class Cliente:
    def __init__ (self, nome, cpf):
        self.nome = nome
        self.__cpf = cpf

    @property
    def cpf(self):
        return self.__cpf

    def exibir_info(self):
        print(f"Cliente: {self.nome}\nCPF: {self.__cpf}")