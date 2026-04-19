from abc import ABC, abstractmethod

class Seguro(ABC):
    def __init__(self, titular, valor_base):
        self._titular = titular
        self._valor_base = valor_base

    @abstractmethod
    def calcular_premio(self):
        pass