class SeguroVeiculo:
    def __init__(self, valor_base, vigencia):
        self.valor_base = valor_base
        self.vigencia = vigencia

    def calcular_valor(self):
        raise NotImplementedError("Este método deve ser sobrescrito pelas subclasses")

class SeguroCarro(SeguroVeiculo):
    def calcular_valor(self):
        return self.valor_base * 1.1

class SeguroMoto(SeguroVeiculo):
    def calcular_valor(self):
        return self.valor_base * 1.2
