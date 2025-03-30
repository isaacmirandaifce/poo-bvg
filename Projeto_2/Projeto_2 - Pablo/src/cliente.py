class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.__cpf = cpf  # Atributo privado, protegido de acesso direto

    # Método público para acessar o CPF (getter)
    def get_cpf(self):
        return self.__cpf

    # Método público para modificar o CPF (setter)
    def set_cpf(self, cpf):
        self.__cpf = cpf

    # Método para exibir as informações do cliente (exemplo de uso)
    def exibir_informacoes(self):
        print(f"Nome: {self.nome}")
        print(f"CPF: {self.get_cpf()}")