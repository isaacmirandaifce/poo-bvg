"""Código de Alissa Garcia Moreira ADS S3 (POO)"""

from Veiculos_Seguro import Veiculos_Seguro

class Carro(Veiculos_Seguro):
    def __init__(self, ano, marca, modelo, cor, placa, tipo_combustivel):
        super().__init__(ano, marca, modelo, cor, placa) 
        self.tipo_combustivel = tipo_combustivel 
#CARRO HERDOU OS ATRIBUTOS DE VEÍCULO E TEM UM NOVO ATRIBUTO CHAMADO TIPO DE COMBUSTÍVEL(COLOQUEI APENAS PARA DIFERENCIAR)

