from abc import ABC, abstractmethod
from models.cliente import Cliente

class Seguro(ABC):
    def __init__(self, titular: Cliente, valorBase: float):
        self.__titularCarro = titular
        self.__valorCarro = valorBase

    @property
    def titular(self) -> Cliente:
        return self.__titularCarro
    
    @property
    def valor(self) -> float:
        return self.__valorCarro
    
    @abstractmethod
    def calcular_premio(self) -> float:
        pass