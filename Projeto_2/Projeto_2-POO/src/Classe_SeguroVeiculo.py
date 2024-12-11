# Classe Base
class SeguroVeiculo:
    def __init__(self, cliente, valor, vigencia):
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        """Calcula o valor básico do seguro"""
        self.valor = base_valor * (1 + taxa)
        return self.valor







