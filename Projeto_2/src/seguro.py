from .seguro_veiculo import SeguroVeiculo
from datetime import date

class SeguroCarro(SeguroVeiculo):
    
    """Seguro específico para carro — pode ter regras específicas."""
    
    def __init__(self, carro, cliente, valor: float, vigencia_inicio: date, vigencia_fim: date, franquia: float = 0.0):
        super().__init__(carro, cliente, valor, vigencia_inicio, vigencia_fim)
        self.franquia = franquia

    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        
        # exemplo: carros com seguro têm acréscimo fixo de franquia no cálculo
        
        return base_valor * (1 + taxa) + self.franquia


class SeguroMoto(SeguroVeiculo):
    
    """Seguro específico para moto — outro cálculo de exemplo."""
    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        
        # exemplo: motos podem ter taxa diferente (aqui apenas demonstrativo)
        
        return base_valor * (1 + taxa * 1.1)