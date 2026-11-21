
from abc import ABC, abstractmethod


class Seguro(ABC):

    def __init__(self, titular, valor_base: float):
        self.__titular = titular
        self.__valor_base = valor_base

    @property
    def titular(self):
        return self.__titular

    @property
    def valor_base(self) -> float:
        return self.__valor_base

    @abstractmethod
    def calcular_premio(self) -> float:
        pass




class SeguroAuto(Seguro):

    def __init__(
        self, titular, valor_base: float, placa: str, ano: int
    ):
        super().__init__(titular, valor_base)
        self.__placa = placa
        self.__ano = ano

    @property
    def placa(self) -> str:
        return self.__placa

    @property
    def ano(self) -> int:
        return self.__ano

    def calcular_premio(self) -> float:
        if self.__ano < 2010:
            return self.valor_base * 1.20

        return self.valor_base * 1.05


class SeguroVida(Seguro):

    def __init__(self, titular, valor_base: float, idade: int):
        super().__init__(titular, valor_base)
        self.__idade = idade

    @property
    def idade(self) -> int:
        return self.__idade

    def calcular_premio(self) -> float:
        if self.__idade > 60:
            return self.valor_base * 2.0

        return self.valor_base * 1.10


class SeguroResidencial(Seguro):

    def __init__(
        self, titular, valor_base: float, tipo_imovel: str
    ):
        super().__init__(titular, valor_base)
        self.__tipo_imovel = tipo_imovel

    @property
    def tipo_imovel(self) -> str:
        return self.__tipo_imovel

    def calcular_premio(self) -> float:

        if self.__tipo_imovel.upper() == "CASA":
            return self.valor_base * 1.15

        return self.valor_base * 1.05

