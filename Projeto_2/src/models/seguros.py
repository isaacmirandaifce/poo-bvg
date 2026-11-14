from abc import ABC, abstractmethod

class Seguro(ABC):
    """
    Classe base abstrata que define o contrato para todos os tipos de seguros.
    O módulo 'abc' impede que esta classe seja instanciada diretamente.
    """
    def __init__(self, titular, valor_base):
        """
        Args:
            titular (Cliente): Objeto Cliente que representa o dono do seguro.
            valor_base (float): Valor inicial para o cálculo do prémio.
        """
        self.titular = titular
        self.valor_base = valor_base
        
    @abstractmethod
    def calcular_premio(self):
        """
        Método abstrato polimórfico. 
        Obriga todas as subclasses a implementarem a sua própria lógica de cálculo.
        """
        pass


class SeguroAuto(Seguro):
    """Especialização para seguros de automóveis."""
    
    def __init__(self, titular, valor_base, placa, ano):
        super().__init__(titular, valor_base)
        self.__placa = placa  #Encapsulamento: Placa protegida como dado sensível
        self.ano = ano
        
    def calcular_premio(self):
        """Se o carro for anterior a 2010, aplica taxa de 20%. Caso contrário, 5%."""
        if self.ano < 2010:
            return self.valor_base * 1.2
        return self.valor_base * 1.05


class SeguroVida(Seguro):
    """Especialização para seguros de vida."""
    
    def __init__(self, titular, valor_base, idade):
        super().__init__(titular, valor_base)
        self.idade = idade
        
    @property
    def idade(self):
        """Retorna a idade do titular."""
        return self.__idade
        
    @idade.setter
    def idade(self, valor):
        """Valida a idade para garantir que é maior que zero."""
        if valor <= 0:
            raise ValueError("Erro: A idade deve ser MAIOR que ZERO!")
        self.__idade = valor
        
    def calcular_premio(self):
        """Se a idade for superior a 60 anos, dobra o valor. Caso contrário, aplica 10%."""
        if self.idade > 60:
            return self.valor_base * 2.0
        return self.valor_base * 1.1

class SeguroResidencial(Seguro):
    """Especialização para seguros residenciais."""
    
    def __init__(self, titular, valor_base, tipo_imovel):
        super().__init__(titular, valor_base)
        self.tipo_imovel = tipo_imovel.upper()  
        
    def calcular_premio(self):
        """Se for CASA, aplica taxa de 15%. Outros imóveis (ex: apartamento) aplicam 5%."""
        if self.tipo_imovel == "CASA":
            return self.valor_base * 1.15
        return self.valor_base * 1.05