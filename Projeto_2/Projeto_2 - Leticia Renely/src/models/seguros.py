from abc import ABC, abstractmethod

class Seguro(ABC):
    def __init__(self, titular, valor_base):
        self._titular = titular
        self._valor_base = valor_base

    @abstractmethod
    def calcular_premio(self):
        pass

class SeguroAuto(Seguro):
    def __init__(self, titular, valor_base, ano):
        super().__init__(titular, valor_base)
        self.__ano = ano

    def calcular_premio(self):
        if self.__ano < 2010:
            return self._valor_base * 1.2
        return self._valor_base * 1.05


class SeguroVida(Seguro):
    def __init__(self, titular, valor_base, idade):
        super().__init__(titular, valor_base)
        self.__idade = idade

    def calcular_premio(self):
        if self.__idade > 60:
            return self._valor_base * 2.0
        return self._valor_base * 1.1


class SeguroResidencial(Seguro):
    def __init__(self, titular, valor_base, tipo_imovel):
        super().__init__(titular, valor_base)
        self.__tipo_imovel = tipo_imovel

    def calcular_premio(self):
        if self.__tipo_imovel.upper() == "CASA":
            return self._valor_base * 1.15
        return self._valor_base * 1.05