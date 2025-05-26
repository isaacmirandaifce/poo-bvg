from src.modelo import Modelo

class Carro:
    def __init__(self, ano, marca, modelo: Modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.__placa = placa

    def get_placa(self):
        return self.__placa

    def exibir_detalhes(self):
        print(f"{self.marca} {self.modelo.nome}, {self.ano}, Cor: {self.cor}, Placa: {self.__placa}")

    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor
