class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.__placa = placa  # Encapsulamento

    def exibir_detalhes(self):
        return f"{self.marca} {self.modelo}, Ano: {self.ano}, Cor: {self.cor}, Placa: {self.__placa}"

    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor

    def get_placa(self):
        return self.__placa
