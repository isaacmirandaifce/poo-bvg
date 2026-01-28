"""Código de Alissa Garcia Moreira ADS S3 (POO)"""

class Cliente:
    def __init__(self, nome, CPF):
        self.nome = nome
        self.__CPF = CPF
    """CPF foi encapsulado"""

    def exibir_informacoes(self):
        print(f"O Cliente {self.nome} tem CPF: {self.__CPF}")
#ATENÇÃO ESSA FUNÇÃO EXIBE O CPF DO CLIENTE!
