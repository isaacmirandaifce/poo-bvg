class SeguroVeiculo:
    def __init__(self, valor_base, vigencia):
        self.valor_base = valor_base
        self.vigencia = vigencia

    def calcular_valor(self, taxa):
        return self.valor_base * (1 + taxa)

class SeguroCarro(SeguroVeiculo):
    def calcular_valor(self, taxa):
        return super().calcular_valor(taxa) + 200

class SeguroMoto(SeguroVeiculo):
    def calcular_valor(self, taxa):
        return super().calcular_valor(taxa) + 100
