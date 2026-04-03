class Cliente:
    def __init__(self, nome, idade, saldo):
        # Atributos 
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    # Mostrar as informações do cliente
    def mostrar_informacoes(self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo}")

    # Atualizar o saldo do cliente
    def atualizar_saldo(self, valor):
        self.__saldo += valor


# Código de teste da classe Cliente
cliente1 = Cliente("João Silva", 30, 1000.0)
cliente1.mostrar_informacoes()
cliente1.atualizar_saldo(500.0)
cliente1.mostrar_informacoes()
