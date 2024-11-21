#Criar classe Cliente
class Cliente:

    # Definir construtor da classe Cliente que vai conter as informações: nome, idade e valor
    def __init__(self, nome:str, idade:int, valor:float):
        
        #Definir que as váriaveis são privadas usando "__"
        self.__nome = nome
        self.__idade = idade
        self.__valor = valor 

    #Definindo metodo para exibir informações
    def mostrar_informacoes(self):
        print("Nome do cliente:", self.__nome, "Idade do cliente:", self.__idade, "Saldo do Cliente:", self.__valor)
    
    #Definindo metodo para exibir o saldo
    def atualizar_saldo(self, saldo: float):
        self.__valor += saldo



