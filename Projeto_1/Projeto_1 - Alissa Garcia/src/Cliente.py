"""Código de Alissa Garcia Moreira ADS S3 (POO)"""

class Clientes:
    def __init__(self, nome, idade, saldo):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    """Startando os atributos que serão usados"""

    def mostrar_informacoes(self):
        print(f"O Cliente: {self.__nome}, tem Idade: {self.__idade} e possui Saldo de {self.__saldo}")

    """Função que mostra os dados do Cliente inserido"""

    def atualizar_saldo(self, valor):
        self.__saldo += valor

    """Função que recebe determinado valor e atualiza o saldo do cliente"""

"""Implementação da classe cliente"""