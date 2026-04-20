"""Código de Alissa Garcia Moreira ADS S3 (POO)"""

from Veiculos_Seguro import Veiculos_Seguro

class Moto(Veiculos_Seguro):
    def __init__(self, ano, marca, modelo, cor, placa, cilindragem):
        super().__init__(ano, marca, modelo, cor, placa) 
        self.cilindragem = cilindragem 
#CARRO HERDOU OS ATRIBUTOS DE VEÍCULO E TEM UM NOVO ATRIBUTO CHAMADO CILINDRAGEM (COLOQUEI APENAS PARA DIFERENCIAR)

