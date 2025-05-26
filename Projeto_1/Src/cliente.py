class Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        # Atributos privados
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_informacoes(self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R${self.__saldo:.2f}")

    def atualizar_saldo(self, valor: float):
        self.__saldo += valor

    
    def get_nome(self):
        return self.__nome

    def get_idade(self):
        return self.__idade

    def get_saldo(self):
        return self.__saldo
