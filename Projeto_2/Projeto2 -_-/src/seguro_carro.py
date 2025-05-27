from src.seguro_veiculo import SeguroVeiculo
from src.cliente import Cliente
from src.carro import Carro

class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente: Cliente, carros: list[Carro], valor: float, vigencia: str):
        super().__init__(cliente, valor, vigencia)
        self.carros = carros

    def calcular_valor(self):
        taxa_base = 0.05
        return self.valor * (1 + taxa_base * len(self.carros))