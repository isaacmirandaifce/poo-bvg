from abc import ABC, abstractmethod


# Classe base (abstrata)
class Seguro(ABC):
    def __init__(self, titular, valor_base: float):
        self.titular = titular
        self.valor_base = valor_base

    @abstractmethod
    def calcular_premio(self) -> float:
        pass


# Seguro de automóvel
class SeguroAuto(Seguro):
    def __init__(self, titular, valor_base: float, ano: int):
        super().__init__(titular, valor_base)
        self.ano = ano

    def calcular_premio(self) -> float:
        if self.ano < 2010:
            return self.valor_base * 1.2
        return self.valor_base * 1.05


# Seguro de vida
class SeguroVida(Seguro):
    def __init__(self, titular, valor_base: float, idade: int):
        super().__init__(titular, valor_base)
        self.idade = idade

    def calcular_premio(self) -> float:
        if self.idade > 60:
            return self.valor_base * 2.0
        return self.valor_base * 1.1


# Seguro residencial
class SeguroResidencial(Seguro):
    def __init__(self, titular, valor_base: float, tipo_imovel: str):
        super().__init__(titular, valor_base)
        self.tipo_imovel = tipo_imovel

    def calcular_premio(self) -> float:
        if self.tipo_imovel.upper() == "CASA":
            return self.valor_base * 1.15
        return self.valor_base * 1.05