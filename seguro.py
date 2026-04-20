class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        return base_valor + (base_valor * taxa)

    def verificar_vigencia(self):
        return "Seguro válido"
