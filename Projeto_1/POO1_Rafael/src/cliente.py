class Cliente:
    # Método de inicialização de um onjeto
    def __init__(self, nome: str, idade: int, saldo: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    # Método para mostrar as informações do objeto criado
    def mostrar_informacoes(self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R$ {self.__saldo:.2f}")

    # Método para atualizar o valor do Saldo
    def atualizar_saldo(self, valor: float):
        self.__saldo += valor

    # Getter usado no input
    def get_nome(self):
        return self.__nome