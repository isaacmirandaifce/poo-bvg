# Class cliente com nome, idade e saldo inicial:

class Cliente: 
    def  __init__ (self, nome: str, idade: int, saldo: float):
        self.__nome = nome 
        self.__idade = idade
        self.__saldo = saldo

# Retornar uma representação em string do cliente::

    def mostrar_informacoes (self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R$ {self.__saldo: .2f}")

    def att_saldo (self, valor: float):
        self.__saldo += valor 

    def get_saldo (self) -> float: 
        self.__saldo 

    def set_saldo (self, novo_saldo: float):
        if novo_saldo >= 0:
            self.__saldo = novo_saldo
        else: 
            print("Erro!")