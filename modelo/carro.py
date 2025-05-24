class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):

        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.__placa = placa

        
    def exibir_detalhes(self):
            print(f"Carro: {self.ano}, {self.marca}, {self.modelo}")
            print(f"Cor: {self.cor}")
            print(f"Placa: {self.__placa}")

    def atualizar_cor(self, nova_cor):
                self.cor= nova_cor
                print(f"A nova cor é: {self.cor}")
               


