from abc import ABC, abstractmethod
from models.cliente import cliente

class seguro(ABC):
    def __init__(self, titular: cliente, valorBase: float):
        self.__titularCarro = titular
        self.__valorCarro = valorBase

    @property
    def titular(self) -> cliente:
        return self.__titularCarro
    
    @property
    def valor(self) -> float:
        return self.__valorCarro
    
    @abstractmethod
    def calcular_premio(self) -> float:
        pass

class seguroAutomovel(seguro):
    def __init__(self, titular: cliente, valorCarro: float, anoVeiculo: int, placaVeiculo: str):
        super.__init__(titular, valorCarro)
        self.__anoCarro = anoVeiculo
        self.__placaCarro = placaVeiculo

    def calcular_premio(self) -> float:
        if self.__anoCarro < 2010:
            return self.__valorCarro * 1.2
        else:
            return self.__valorCarro * 1.05
        
class seguroVida(seguro):
    def __init__(self, titular: cliente, valorCarro: float, idadeCliente: int):
        super.__init__(titular, valorCarro)
        self.__idade = idadeCliente

    def calcular_premio(self) -> float:
        if self.__idade > 60:
            return self.__valorCarro * 2
        else:
            return self.__valorCarro * 1.1

        