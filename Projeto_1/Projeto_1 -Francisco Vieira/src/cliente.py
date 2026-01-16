# cliente.py
# Autor: [|Francisco]
# Data: [21/10/2025]

class Cliente:
    def __init__(self, nome, idade, saldo):

        # atributos privados (encapsulamento)
        
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    # mostra as informações do cliente

    def mostrar_informacoes(self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R$ {self.__saldo:.2f}")

    # atualiza o saldo (aceita positivo ou negativo)

    def atualizar_saldo(self, valor):
        try:
            v = float(valor)
        except:
            raise ValueError("valor deve ser numérico")
        self.__saldo += v

    # getters simples

    def get_nome(self):
        return self.__nome

    def get_idade(self):
        return self.__idade

    def get_saldo(self):
        return self.__saldo 
