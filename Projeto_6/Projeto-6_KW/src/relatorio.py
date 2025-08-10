from abc import ABC, abstractmethod

class Relatorio(ABC):
    @abstractmethod
    def gerar_relatorio(self):
        pass