# relatorio.py
from abc import ABC, abstractmethod

class Relatorio(ABC):
    """
    Interface que define um contrato para a geração de relatórios.
    Classes que implementam esta interface devem fornecer o método gerar_relatorio.
    """
    @abstractmethod
    def gerar_relatorio(self) -> None:
        """Método virtual puro (abstrato) para gerar um relatório."""
        pass