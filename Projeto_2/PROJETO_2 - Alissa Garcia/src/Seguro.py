"""Código de Alissa Garcia Moreira ADS S3 (POO)"""

from datetime import datetime

class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.__carro = carro
        self.__cliente = cliente
        self.__valor = valor
        self.__vigencia = vigencia
        """Todos foram encapsulados por se tratarem de dados sensíveis para a empresa"""
    
    def calcular_valor(self, valor_base, taxa):
        valor_atualizado = valor_base + (valor_base * taxa)
        self.__valor = valor_atualizado
        return valor_atualizado
#CALCULA, ATUALIZA E RETORNA O VALOR DO SEGURO CONFORME A TAXA DADA NO PARÂMETRO DE ENTRADA.

    def verificar_vigencia(self):
        data_de_hoje = datetime.now().date
        data_da_vigencia = datetime.strptime(self.__vigencia, "%d-%m-%Y").date()

        if data_de_hoje > data_da_vigencia:
            return "Seguro Vencido!"
        if data_de_hoje == data_da_vigencia:
            return "Seguro prestes a vencer (AMANHÃ)"
        if data_de_hoje < data_da_vigencia:
            return "Seguro Válido!"
        else:
            return "ERRO"
#VERIFICA A VIGENCIA DO SEGURO CONFORME A DATA ATUAL


