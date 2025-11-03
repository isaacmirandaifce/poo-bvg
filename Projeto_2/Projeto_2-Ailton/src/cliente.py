class Cliente:
    def __init__(self, nome, cpf):
        # Inicializa os atributos do cliente
        self.nome = nome
        self.__cpf = cpf # encapsulamento do CPF do cliente

    def exibir_informacoes(self):
        # Exibe as informações do cliente, incluindo o CPF encapsulado
        print(f"Cliente: {self.nome} - CPF: {self.__cpf}")

    def get_cpf(self):
        # Método para acessar o CPF encapsulado
        return self.__cpf