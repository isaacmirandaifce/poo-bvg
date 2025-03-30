from datetime import datetime

class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.placa = placa

    def exibir_detalhes(self):
        print(f"Ano: {self.ano}, Marca: {self.marca}, Modelo: {self.modelo}, Cor: {self.cor}, Placa: {self.placa}")

    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor
        print(f"A cor do carro foi atualizada para {self.cor}")