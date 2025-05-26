from abc import ABC, abstractmethod
from datetime import datetime
from src.cliente import Cliente

class SeguroVeiculo(ABC):
    def __init__(self, cliente: Cliente, valor: float, vigencia: str):
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    @abstractmethod
    def calcular_valor(self):
        pass

    def verificar_vigencia(self):
        hoje = datetime.today()
        try:
            data_fim = self.vigencia.split(" a ")[1]
            fim = datetime.strptime(data_fim, "%d/%m/%Y")
            return hoje <= fim
        except:
            return False
