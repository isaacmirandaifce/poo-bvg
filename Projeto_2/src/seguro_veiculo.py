from datetime import date

class SeguroVeiculo:
    def __init__(self, cliente, valor, data_inicio, data_fim):
        self.cliente = cliente
        self.valor = valor
        self.data_inicio = data_inicio
        self.data_fim = data_fim

    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor * (1 + taxa)
        return self.valor

    def verificar_vigencia(self):
        hoje = date.today()
        return self.data_inicio <= hoje <= self.data_fim
