class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.__cor = cor
        self.__placa = placa

    def exibir_detalhes(self):
        return f"{self.ano} {self.marca} {self.modelo} ({self.__cor}), Placa: {self.__placa}"

    def atualizar_cor(self, nova_cor):
        self.__cor = nova_cor

    def get_placa(self):
        return self.__placa
