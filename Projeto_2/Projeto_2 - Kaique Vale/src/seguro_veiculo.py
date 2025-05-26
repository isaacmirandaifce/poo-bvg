class SeguroVeiculo:
    def calcular_valor(self, base_valor, taxa):
        return base_valor * (1 + taxa)

class SeguroCarro(SeguroVeiculo):
    def calcular_valor(self, base_valor, taxa):
        return base_valor * (1 + taxa + 0.1)  # taxa extra para carro

class SeguroMoto(SeguroVeiculo):
    def calcular_valor(self, base_valor, taxa):
        return base_valor * (1 + taxa + 0.05)  # taxa extra menor para moto
