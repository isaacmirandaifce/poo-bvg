from Classe_SeguroVeiculo import SeguroVeiculo

# Subclasse para Motos
class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente, valor, vigencia, cilindradas, tipo_moto):
        super().__init__(cliente, valor, vigencia)
        self.cilindradas = cilindradas
        self.tipo_moto = tipo_moto

    def calcular_valor(self, base_valor, taxa):
        """Calcula o valor do seguro para motos com base nas cilindradas."""
        if self.cilindradas > 500:
            taxa += 0.1  # Taxa adicional para motos potentes
        self.valor = base_valor * (1 + taxa)
        return self.valor