from .seguro_veiculo import SeguroVeiculo

class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente, valor, vigencia, cilindrada):
        super().__init__(cliente, valor, vigencia)
        self.cilindrada = cilindrada

    def calcular_valor(self, base_valor, taxa):
        desconto = 0.02 if self.cilindrada < 250 else 0  # Desconto para baixa cilindrada
        self.valor = base_valor + (base_valor * taxa) - (base_valor * desconto)
        return self.valor