from seguro_veiculo import SeguroVeiculo

class SeguroMoto(SeguroVeiculo):
    def calcular_valor(self, valor_base):
        return valor_base + 100
