class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.placa = placa

    def exibir_detalhes(self):
        detalhes = f"{self.ano} {self.marca} {self.modelo} - Cor: {self.cor}, Placa: {self.placa}"
        print(detalhes)
        return detalhes 

    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor