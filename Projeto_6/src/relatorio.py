from abc import ABC, abstractmethod

class Relatorio(ABC):
    @abstractmethod
    def gerar_relatorio(self):
        """
        Método abstrato que deve ser implementado pelas classes que herdarem esta interface.
        Define o padrão para a geração de relatórios.
        """
        pass
