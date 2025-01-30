class Cliente:
    def __init__(self, nome, idade, saldo):
        # Inicializa os atributos do cliente
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    # Método para exibir as informações do cliente
    def mostrar_informacoes(self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo}")

    # Método para atualizar o saldo do cliente
    def atualizar_saldo(self, valor):
        self.__saldo += valor

    # Métodos getter para acessar os atributos de forma controlada
    def get_nome(self):
        return self.__nome

    def get_idade(self):
        return self.__idade

    def get_saldo(self):
        return self.__saldo
