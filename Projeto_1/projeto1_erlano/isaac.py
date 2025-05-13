class Cliente:

    #Inicialização dos objetos da classe
    def __init__(self, nome: str, idade: int, saldo: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    #Mostra as informaçãoes do objeto
    def mostrar_informacoes(self):
        print(f"nome: {self.__nome}, idade: {self.__idade}, saldo: {self.__saldo}\n")

    #Atualiza o valor do saldo do objeto
    def atualizar_saldo(self, valor: float):
        self.__saldo = self.__saldo + valor