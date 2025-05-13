class Cliente:
    #definiçao de atributos
    def __init__(self, nome: str, idade: int, saldo: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    #metodo de mostrar os atributos
    def mostrar_informacoes(self):
        print(f"Cliente: {self.__nome}")
        print(f"Idade: {self.__idade}")
        print(f"Saldo: R$ {self.__saldo:.2f}")

    #metedo de alteraçao do saldo
    def atualizar_saldo(self, valor):
        self.__saldo += valor