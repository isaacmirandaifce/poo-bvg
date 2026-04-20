from seguro_veiculo import SeguroVeiculo

class SeguroCarro(SeguroVeiculo):
    def calcular_valor(self, valor_base):
        return valor_base + 200
