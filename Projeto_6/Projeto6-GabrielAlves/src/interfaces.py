from abc import ABC, abstractmethod

class Relatorio(ABC):
    """
    Interface que define um contrato para a geração de relatórios. 
    Qualquer classe que implementar esta interface deve fornecer uma
    implementação para o método gerar_relatorio. 
    """
    @abstractmethod
    def gerar_relatorio(self) -> None:
        """
        Método abstrato para gerar um relatório específico do usuário. 
        """
        pass