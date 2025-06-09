from seguro_veiculo import SeguroVeiculo

class SeguroCarro(SeguroVeiculo):
    def calcular_valor(self, base_valor, taxa):
        # Cálculo específico para carro
        self.valor = base_valor * taxa * len(self.carros)
        return self.valor


class SeguroMoto(SeguroVeiculo):
    def calcular_valor(self, base_valor, taxa):
        # Cálculo específico para moto
        self.valor = (base_valor * taxa) * 0.8
        return self.valor