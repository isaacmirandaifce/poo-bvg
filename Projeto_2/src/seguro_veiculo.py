from datetime import date

class SeguroVeiculo:
    
    """Classe base para seguros de veículos."""
    
    def __init__(self, carro, cliente, valor: float, vigencia_inicio: date, vigencia_fim: date):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia_inicio = vigencia_inicio
        self.vigencia_fim = vigencia_fim

    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        
        """Cálculo base — subclasses podem sobrescrever."""
        
        return base_valor * (1 + taxa)

    def verificar_vigencia(self) -> bool:
        
        hoje = date.today()
        
        return self.vigencia_inicio <= hoje <= self.vigencia_fim