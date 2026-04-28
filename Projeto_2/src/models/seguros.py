from abc import ABC, abstractmethod
from models.cliente import cliente

class seguro(ABC):
    def __init__(self, titular: cliente, valorBase: float):
        self.__titularCarro = titular
        self.__valor = valorBase

    @property
    def titular(self) -> cliente:
        return self.__titularCarro
    
    @property
    def valor(self) -> float:
        return self.__valor
    
    @abstractmethod
    def calcular_premio(self) -> float:
        pass

class seguroAutomovel(seguro):
    def __init__(self, titular: cliente, valor: float, anoVeiculo: int, placaVeiculo: str):
        super.__init__(titular, valor)
        self.__anoCarro = anoVeiculo
        self.__placaCarro = placaVeiculo

    def calcular_premio(self) -> float:
        if self.__anoCarro < 2010:
            return self.__valor * 1.2
        else:
            return self.__valor * 1.05
        
class seguroVida(seguro):
    def __init__(self, titular: cliente, valor: float, idadeCliente: int):
        super.__init__(titular, valor)
        self.__idade = idadeCliente

    def calcular_premio(self) -> float:
        if self.__idade > 60:
            return self.__valor * 2
        else:
            return self.__valor * 1.1
        
class seguroImovel(seguro):
    def __init__(self, titular: cliente, valor: float, tipoImovel: str):
        super.__init__(titular, valor)
        self.__imovel = tipoImovel

    def calcular_premio(self) -> float:
        if self.__imovel == "casa":
            return self.__valor * 1.15
        else:
            return self.__valor * 1.06
        


        