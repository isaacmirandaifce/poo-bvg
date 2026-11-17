from abc import ABC, abstractmethod

class Seguro(ABC):
    """
    Classe base abstrata que define o contrato para todos os tipos de seguros.
    O módulo 'abc' impede que esta classe seja instanciada diretamente.
    """
    def __init__(self, titular, valor_base):
        """
        Construtor da classe Seguro.
        
        Args:
            titular (Cliente): Objeto Cliente que representa o dono do seguro.
            valor_base (float): Valor inicial para o cálculo do prémio.
            
        Raises:
            ValueError: Se o valor base for menor ou igual a zero.
        """
        self.titular = titular
        self.valor_base = valor_base  
        
        # Associação Bidirecional
        # O Seguro amarra-se automaticamente à lista de seguros do Cliente
        if hasattr(self.titular, 'adicionar_seguro'):
            self.titular.adicionar_seguro(self)
            
    @property
    def valor_base(self):
        """Retorna o valor base do seguro."""
        return self.__valor_base
        
    @valor_base.setter
    def valor_base(self, valor):
        """Valida se o valor base é estritamente positivo (Ponto 6)."""
        if valor <= 0:
            raise ValueError("Erro: O valor base deve ser maior que zero.")
        self.__valor_base = valor
        
    @abstractmethod
    def calcular_premio(self):
        """
        Método abstrato polimórfico. 
        Obriga todas as subclasses a implementarem a sua própria lógica de cálculo.
        
        Returns:
            float: Valor final calculado do prêmio.
        """
        pass


class SeguroAuto(Seguro):
    """Especialização para seguros de automóveis."""
    
    def __init__(self, titular, valor_base, placa, ano):
        """
        Construtor da classe SeguroAuto.
        
        Args:
            titular (Cliente): Dono do seguro.
            valor_base (float): Valor inicial para cálculo.
            placa (str): Placa do veículo (dado sensível).
            ano (int): Ano de fabricação do veículo.
        """
        super().__init__(titular, valor_base)
        self.__placa = placa  #Encapsulamento: Placa protegida como dado sensível
        self.ano = ano  #Dispara a validação do setter
        
    @property
    def placa(self):
        """Retorna a placa do carro de forma segura (apenas leitura)."""
        return self.__placa
        
    @property
    def ano(self):
        """Retorna o ano do veículo."""
        return self.__ano
        
    @ano.setter
    def ano(self, valor):
        """Valida se o ano é um valor lógico para veículos (Ponto 6)."""
        if valor < 1886:  #Ano do primeiro automóvel inventado
            raise ValueError("Erro: Ano do veículo inválido.")
        self.__ano = valor
        
    def calcular_premio(self):
        """
        Calcula o prêmio do seguro auto.
        Se o carro for anterior a 2010, aplica taxa de 20%. Caso contrário, 5%.
        
        Returns:
            float: Valor do prêmio do carro.
        """
        if self.ano < 2010:
            return self.valor_base * 1.2
        return self.valor_base * 1.05


class SeguroVida(Seguro):
    """Especialização para seguros de vida."""
    
    def __init__(self, titular, valor_base, idade):
        """
        Construtor da classe SeguroVida.
        
        Args:
            titular (Cliente): Dono do seguro.
            valor_base (float): Valor inicial para cálculo.
            idade (int): Idade do titular.
        """
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
        """
        Calcula o prêmio do seguro de vida.
        Se a idade for superior a 60 anos, dobra o valor. Caso contrário, aplica 10%.
        
        Returns:
            float: Valor do prêmio de vida.
        """
        if self.idade > 60:
            return self.valor_base * 2.0
        return self.valor_base * 1.1


class SeguroResidencial(Seguro):
    """Especialização para seguros residenciais."""
    
    def __init__(self, titular, valor_base, tipo_imovel):
        """
        Construtor da classe SeguroResidencial.
        
        Args:
            titular (Cliente): Dono do seguro.
            valor_base (float): Valor inicial para cálculo.
            tipo_imovel (str): Categoria do imóvel ('CASA' ou 'APARTAMENTO').
        """
        super().__init__(titular, valor_base)
        self.tipo_imovel = tipo_imovel  #Dispara a validação do setter
        
    @property
    def tipo_imovel(self):
        """Retorna o tipo de imóvel."""
        return self.__tipo_imovel
        
    @tipo_imovel.setter
    def tipo_imovel(self, valor):
        """Valida e garante que apenas CASA ou APARTAMENTO sejam aceites (Ponto 6)."""
        v_upper = str(valor).upper()
        if v_upper not in ["CASA", "APARTAMENTO"]:
            raise ValueError("Erro: Tipo de imóvel inválido. Utilize 'CASA' ou 'APARTAMENTO'.")
        self.__tipo_imovel = v_upper
        
    def calcular_premio(self):
        """
        Calcula o prêmio do seguro residencial.
        Se for CASA, aplica taxa de 15%. APARTAMENTO (ou outros válidos) aplicam 5%.
        
        Returns:
            float: Valor do prêmio residencial.
        """
        if self.tipo_imovel == "CASA":
            return self.valor_base * 1.15
        return self.valor_base * 1.05