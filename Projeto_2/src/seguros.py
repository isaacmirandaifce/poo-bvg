"""Módulo contendo a hierarquia de Seguros da InsureTech Pro."""

from abc import ABC, abstractmethod
from .cliente import Cliente

class Seguro(ABC):
    """Classe base abstrata que define o contrato para todos os seguros."""
    
    def __init__(self, titular: Cliente, valor_base: float):
        """
        Inicializa um Seguro genérico.
        
        Args:
            titular (Cliente): Objeto Cliente associado ao seguro.
            valor_base (float): Valor financeiro base para o cálculo do prêmio.
        """
        self._titular = titular
        self._valor_base = valor_base
        
    @property
    def titular(self) -> Cliente:
        """Retorna o titular do seguro."""
        return self._titular
        
    @abstractmethod
    def calcular_premio(self) -> float:
        """
        Calcula o valor final do prêmio.
        Método abstrato que deve ser obrigatoriamente implementado pelas subclasses.
        """
        pass


class SeguroAuto(Seguro):
    """Especialização para Seguros de Automóveis."""
    
    def __init__(self, titular: Cliente, valor_base: float, placa: str, ano: int):
        super().__init__(titular, valor_base)
        self.__placa = placa  # Encapsulamento da placa do veículo
        self.ano = ano
        
    def calcular_premio(self) -> float:
        """
        Calcula o prêmio do automóvel.
        Veículos anteriores a 2010 têm acréscimo de 20%, os demais 5%.
        """
        if self.ano < 2010:
            return self._valor_base * 1.2
        return self._valor_base * 1.05


class SeguroVida(Seguro):
    """Especialização para Seguros de Vida."""
    
    def __init__(self, titular: Cliente, valor_base: float, idade: int):
        super().__init__(titular, valor_base)
        self.idade = idade
        
    def calcular_premio(self) -> float:
        """
        Calcula o prêmio de vida.
        Pessoas acima de 60 anos pagam o dobro, as demais têm acréscimo de 10%.
        """
        if self.idade > 60:
            return self._valor_base * 2.0
        return self._valor_base * 1.1


class SeguroResidencial(Seguro):
    """Especialização para Seguros Residenciais."""
    
    def __init__(self, titular: Cliente, valor_base: float, tipo_residencia: str):
        super().__init__(titular, valor_base)
        self.tipo_residencia = tipo_residencia.upper()
        
    def calcular_premio(self) -> float:
        """
        Calcula o prêmio residencial.
        Casas têm acréscimo de 15%, apartamentos/outros 5%.
        """
        if self.tipo_residencia == "CASA":
            return self._valor_base * 1.15
        return self._valor_base * 1.05