class Moto:
    def __init__(self, marca, modelo, ano, placa):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.__placa = placa

    def get_placa(self):
        return self.__placa

    def exibir_detalhes(self):
        print(f"{self.marca} {self.modelo}, {self.ano}, Placa: {self.__placa}")