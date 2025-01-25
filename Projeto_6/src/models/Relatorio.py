from abc import ABC, abstractmethod

class Relatorio(ABC):
    @abstractmethod
    def gerarRelatorio(self):
        pass
