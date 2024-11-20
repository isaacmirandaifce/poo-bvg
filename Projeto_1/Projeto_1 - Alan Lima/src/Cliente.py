
class Cliente:
    def __init__(self,nome,idade,saldo):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo
    
    def mostrar_informacoes(self):
        print(f'Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo}')

    def atualizar_saldo(self,valor):
        self.__saldo += valor
    
    
    def get_nome(self):
        return self.__nome

    def get_idade(self):
        return self.__idade

    def get_saldo(self):
        return self.__saldo