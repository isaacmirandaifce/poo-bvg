from typing import List
from .seguro_veiculo import SeguroVeiculo
from .carro import Carro

class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente, valor, vigencia, carros):
        super().__init__(cliente, valor, vigencia)
        self.carros: List[Carro] = carros

    def calcular_valor(self, base_valor, taxa):
        taxa_adicional = 0.05  # Taxa adicional para carros
        self.valor = base_valor + (base_valor * (taxa + taxa_adicional))
        return self.valor