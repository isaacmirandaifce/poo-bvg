class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.placa = placa

    def exibir_detalhes(self):
        print(self.marca, self.modelo, self.ano, self.cor, self.placa)

    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor
