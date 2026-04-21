from abc import ABC, abstractmethod
from src.models.cliente import Cliente


class Seguro(ABC):
    def __init__(self, titular: Cliente, valor_base: float, numero_apolice: str) -> None:
        self._titular = titular
        self._valor_base = valor_base
        self._numero_apolice = numero_apolice

    @abstractmethod
    def calcular_premio(self) -> float:
        pass

    def get_info(self) -> str:
        tipo = type(self).__name__
        return (
            f"[{tipo}] Apólice nº {self._numero_apolice} | "
            f"Titular: {self._titular.get_nome()} | "
            f"Prêmio: R$ {self.calcular_premio():.2f}"
        )

    def __str__(self) -> str:
        return self.get_info()

class SeguroAuto(Seguro):
    def __init__(
        self,
        titular: Cliente,
        valor_base: float,
        numero_apolice: str,
        placa: str,
        ano_fabricacao: int,
        modelo: str,
    ) -> None:
        super().__init__(titular, valor_base, numero_apolice)
        self.__placa = placa           # Dado sensível
        self.__ano_fabricacao = ano_fabricacao
        self.__modelo = modelo

    def calcular_premio(self) -> float:
        if self.__ano_fabricacao < 2010:
            return self._valor_base * 1.20
        return self._valor_base * 1.05

    def get_placa(self) -> str:
        return self.__placa

    def get_modelo(self) -> str:
        return self.__modelo

    def get_ano_fabricacao(self) -> int:
        return self.__ano_fabricacao

class SeguroVida(Seguro):
    def __init__(
        self,
        titular: Cliente,
        valor_base: float,
        numero_apolice: str,
        idade_segurado: int,
        cobertura: str,
    ) -> None:
        super().__init__(titular, valor_base, numero_apolice)
        self.__idade_segurado = idade_segurado
        self.__cobertura = cobertura

    def calcular_premio(self) -> float:
        if self.__idade_segurado > 60:
            return self._valor_base * 2.0
        return self._valor_base * 1.10

    def get_idade(self) -> int:
        return self.__idade_segurado

    def get_cobertura(self) -> str:
        return self.__cobertura

class SeguroResidencial(Seguro):
    TIPOS_VALIDOS = ("CASA", "APARTAMENTO")

    def __init__(
        self,
        titular: Cliente,
        valor_base: float,
        numero_apolice: str,
        tipo_imovel: str,
        endereco: str,
        area_m2: float,
    ) -> None:
        super().__init__(titular, valor_base, numero_apolice)
        tipo_upper = tipo_imovel.upper()
        if tipo_upper not in self.TIPOS_VALIDOS:
            raise ValueError(
                f"Tipo de imóvel inválido: '{tipo_imovel}'. "
                f"Use: {self.TIPOS_VALIDOS}"
            )
        self.__tipo_imovel = tipo_upper
        self.__endereco = endereco
        self.__area_m2 = area_m2

    def calcular_premio(self) -> float:
        if self.__tipo_imovel == "CASA":
            return self._valor_base * 1.15
        return self._valor_base * 1.05

    def get_tipo_imovel(self) -> str:
        return self.__tipo_imovel

    def get_endereco(self) -> str:
        return self.__endereco

    def get_area_m2(self) -> float:
        return self.__area_m2
