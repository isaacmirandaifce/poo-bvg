class Cliente:
    def __init__(self, nome, idade, saldo):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_Infor(self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo}")
    
    def atualizar_saldo(self, valor):
        if valor > 0:
         self.__saldo += valor
        