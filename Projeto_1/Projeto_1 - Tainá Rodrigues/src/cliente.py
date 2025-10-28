class Cliente: #classe criada

    def __init__(self, nome, idade, saldo): #construtor para inicializar os atributos do cliente
       
        self.__nome = nome  #atributos privados; encapsulamento (uso de 2 underlines)
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_informacoes(self): #mostrar as informações do cliente
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R$ {self.__saldo:.2f}")

    def atualizar_saldo(self, valor): #saldo do cliente
        self.__saldo += valor



