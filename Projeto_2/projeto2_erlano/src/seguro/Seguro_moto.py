from src.seguro.Seguro_veiculo import SeguroVeiculo
from src.cliente import Cliente
from src.moto import Moto

class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente: Cliente, moto: Moto, valor: float, vigencia: str):
        super().__init__(cliente, valor, vigencia)
        self.moto = moto

    def calcular_valor(self):
        taxa_base = 0.07
        return self.valor * (1 + taxa_base)