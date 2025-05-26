class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.__ano = ano
        self.__marca = marca
        self.__modelo = modelo
        self.__cor = cor
        self.__placa = placa

    def exibir_detalhes(self):
        print(f"Ano: {self.__ano}, Marca: {self.__marca}, Modelo: {self.__modelo}, Cor: {self.__cor}, Placa: {self.__placa}")

    def atualizar_cor(self, nova_cor):
        self.__cor = nova_cor