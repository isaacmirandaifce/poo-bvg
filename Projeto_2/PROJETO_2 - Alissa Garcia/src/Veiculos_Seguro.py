"""Código de Alissa Garcia Moreira ADS S3 (POO)"""

class Veiculos_Seguro():
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.__placa = placa 
        """O atributo placa foi encapsulado por ser um dado que precisa ser protegido"""
    
    def exibir_detalhes(self):
         print(f"O Veículo com placa {self.__placa} possui o ano: {self.ano}, é do modelo {self.modelo} da marca {self.marca} e tem a cor{self.cor}")
#EXIBE TODAS AS INFORMAÇÕES SOBRE O CARRO (INCLUSIVE A PLACA!)      

    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor
#MODIFICA A COR ORIGINAL PELA FORNECIDA NO PARÂMETRO DE ENTRADA.   