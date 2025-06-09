from datetime import date

class SeguroVeiculo:
    def __init__(self, cliente, carros, valor, vigencia_inicio, vigencia_fim):
        self.cliente = cliente
        self.carros = carros if isinstance(carros, list) else [carros]
        self.valor = valor
        self.vigencia_inicio = vigencia_inicio
        self.vigencia_fim = vigencia_fim

    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor * taxa
        return self.valor

    def verificar_vigencia(self):
        hoje = date.today()
        return self.vigencia_inicio <= hoje <= self.vigencia_fim