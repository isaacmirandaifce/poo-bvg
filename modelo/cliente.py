class Cliente:
    def __init__(self, nome, cpf):
       self.nome= nome
       self.__cpf= cpf

    def exibir_informacoes(self):
         print(f"Nome: {self.nome}")
         print(f"CPF: {self.__cpf}")


        