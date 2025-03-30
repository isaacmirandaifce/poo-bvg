class Cliente:
    def __init__(self, nome_cliente, idade_cliente, saldo_conta):
        self.__nome_cliente = nome_cliente
        self.__idade_cliente = idade_cliente
        self.__saldo_conta = saldo_conta

    def mostrar_informacoes(self):
        print(f'Cliente: {self.__nome_cliente}, Idade: {self.__idade_cliente}, Saldo: {self.__saldo_conta:.2f}')

    def atualizar_saldo(self, valor_atualizacao):
        self.__saldo_conta += valor_atualizacao

    def get_nome_cliente(self):
        return self.__nome_cliente

    def get_idade_cliente(self):
        return self.__idade_cliente

    def get_saldo_conta(self):
        return self.__saldo_conta