from abc import ABC, abstractmethod


class Seguro(ABC):
    """Classe base abstrata para todos os seguros."""

    def __init__(self, titular, valor_base):
        """Inicializa os dados comuns a qualquer seguro.

        Args:
            titular (Cliente): Cliente dono do seguro.
            valor_base (float): Valor base para o cálculo do prêmio.
        """
        self.titular = titular
        self.valor_base = valor_base
        titular.adicionar_seguro(self)

    @abstractmethod
    def calcular_premio(self):
        """Calcula o prêmio. Cada subclasse define sua regra.

        Returns:
            float: Valor final do prêmio.
        """

    def __str__(self):
        """Retorna uma descrição curta do seguro."""
        return f"{type(self).__name__} de {self.titular.nome}"


class SeguroAuto(Seguro):
    """Seguro de automóvel: o prêmio depende do ano do veículo."""

    def __init__(self, titular, valor_base, modelo, ano, placa):
        """Cria um seguro de automóvel.

        Args:
            titular (Cliente): Cliente dono do seguro.
            valor_base (float): Valor base para o cálculo do prêmio.
            modelo (str): Modelo do veículo.
            ano (int): Ano de fabricação.
            placa (str): Placa, armazenada de forma protegida.
        """
        super().__init__(titular, valor_base)
        self.modelo = modelo
        self.ano = ano
        self.__placa = placa

    def calcular_premio(self):
        """Veículos anteriores a 2010 pagam 20% a mais; os demais, 5%."""
        if self.ano < 2010:
            return self.valor_base * 1.2
        return self.valor_base * 1.05


class SeguroVida(Seguro):
    """Seguro de vida: o prêmio depende da idade do segurado."""

    def __init__(self, titular, valor_base, idade):
        """Cria um seguro de vida.

        Args:
            titular (Cliente): Cliente dono do seguro.
            valor_base (float): Valor base para o cálculo do prêmio.
            idade (int): Idade do segurado.
        """
        super().__init__(titular, valor_base)
        self.idade = idade

    def calcular_premio(self):
        """Segurados acima de 60 anos pagam o dobro; os demais, 10% a mais."""
        if self.idade > 60:
            return self.valor_base * 2.0
        return self.valor_base * 1.1


class SeguroResidencial(Seguro):
    """Seguro residencial: o prêmio depende do tipo de imóvel."""

    def __init__(self, titular, valor_base, tipo_imovel):
        """Cria um seguro residencial.

        Args:
            titular (Cliente): Cliente dono do seguro.
            valor_base (float): Valor base para o cálculo do prêmio.
            tipo_imovel (str): "CASA" ou "APARTAMENTO".
        """
        super().__init__(titular, valor_base)
        self.tipo_imovel = tipo_imovel

    def calcular_premio(self):
        """Casas pagam 15% a mais; apartamentos, 5%."""
        if self.tipo_imovel == "CASA":
            return self.valor_base * 1.15
        return self.valor_base * 1.05