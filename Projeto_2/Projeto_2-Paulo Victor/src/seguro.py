from datetime import datetime

class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor + (base_valor * taxa)
        return self.valor

    def verificar_vigencia(self):
        hoje = datetime.now()
        data_fim = datetime.strptime(self.vigencia.split(' a ')[1], "%d/%m/%Y")
        return hoje <= data_fim
