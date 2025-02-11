class SeguroVeiculo:
    def __init__(self, cliente, valor, vigencia):
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor * (1 + taxa)
        return self.valor

    def verificar_vigencia(self, data_atual):
        inicio, fim = self.vigencia.split(" a ")
        return inicio <= data_atual <= fim
