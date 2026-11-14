"""Hierarquia de seguros

Substitui o antigo ``calcular_valor_seguro(tipo, base, detalhe)``, cheio de
``if/else`` sobre strings, por herança e polimorfismo: cada tipo de seguro
sabe calcular o seu próprio prêmio (princípio Aberto/Fechado)."""

from abc import ABC, abstractmethod


class Seguro(ABC):
    """Classe base abstrata de todos os seguros.

    Concentra o que é comum (titular e valor base) e obriga as subclasses a
    implementarem ``calcular_premio()``. Não pode ser instanciada diretamente.

    Attributes:
        titular (Cliente): Cliente titular do seguro.
        valor_base (float): Valor base sobre o qual o prêmio é calculado. """

    def __init__(self, titular, valor_base):
        """Inicializa os atributos comuns e associa o seguro ao titular.

        Args:
            titular (Cliente): Cliente titular do seguro.
            valor_base (float): Valor base do seguro (maior que zero).

        Raises:
            ValueError: Se ``valor_base`` não for positivo."""
        if valor_base <= 0:
            raise ValueError("O valor base deve ser maior que zero.")
        self.titular = titular
        self.valor_base = valor_base
        titular.adicionar_seguro(self)

    @abstractmethod
    def calcular_premio(self):
        """Calcula o valor do prêmio do seguro.

        Cada subclasse define a sua própria regra.

        Returns:
            float: Valor do prêmio."""

    def exibir_detalhes(self):
        """Retorna uma descrição do seguro (método comum às subclasses).

        Returns:
            str: Texto com tipo, titular, valor base e prêmio."""
        return (
            f"{self.__class__.__name__} | Titular: {self.titular.nome} | "
            f"Base: R${self.valor_base:.2f} | Prêmio: R${self.calcular_premio():.2f}"
        )

    def __str__(self):
        return self.exibir_detalhes()


class SeguroAuto(Seguro):
    """Seguro de automóvel. O prêmio depende do ano do veículo.

    Attributes:
        modelo (str): Modelo do veículo.
        ano (int): Ano de fabricação do veículo."""

    ANO_LIMITE = 2010
    FATOR_VEICULO_ANTIGO = 1.2
    FATOR_VEICULO_NOVO = 1.05

    def __init__(self, titular, valor_base, modelo, ano, placa):
        """Cria um seguro de automóvel.

        Args:
            titular (Cliente): Cliente titular.
            valor_base (float): Valor base do seguro.
            modelo (str): Modelo do veículo.
            ano (int): Ano de fabricação do veículo.
            placa (str): Placa do veículo (guardada de forma privada)."""
        super().__init__(titular, valor_base)
        self.modelo = modelo
        self.ano = ano
        self.__placa = placa 

    @property
    def placa_mascarada(self):
        """str: Placa com apenas os 3 primeiros caracteres visíveis."""
        return f"{self.__placa[:3]}****"

    def calcular_premio(self):
        """Calcula o prêmio: veículos anteriores a 2010 pagam mais.

        Returns:
            float: ``valor_base * 1.2`` se ano < 2010; senão ``valor_base * 1.05``."""
        fator = (
            self.FATOR_VEICULO_ANTIGO
            if self.ano < self.ANO_LIMITE
            else self.FATOR_VEICULO_NOVO
        )
        return self.valor_base * fator

    def exibir_detalhes(self):
        """Estende a descrição base com modelo, ano e placa mascarada.

        Returns:
            str: Descrição completa do seguro auto."""
        return (
            f"{super().exibir_detalhes()} | Veículo: {self.modelo} ({self.ano}), "
            f"Placa: {self.placa_mascarada}"
        )


class SeguroVida(Seguro):
    """Seguro de vida. O prêmio depende da idade do segurado.

    Attributes:
        idade (int): Idade do segurado."""

    IDADE_LIMITE = 60
    FATOR_IDOSO = 2.0
    FATOR_PADRAO = 1.1

    def __init__(self, titular, valor_base, idade):
        """Cria um seguro de vida.

        Args:
            titular (Cliente): Cliente titular.
            valor_base (float): Valor base do seguro.
            idade (int): Idade do segurado."""
        super().__init__(titular, valor_base)
        self.idade = idade

    def calcular_premio(self):
        """Calcula o prêmio: segurados acima de 60 anos pagam mais.

        Returns:
            float: ``valor_base * 2.0`` se idade > 60; senão ``valor_base * 1.1``."""
        fator = self.FATOR_IDOSO if self.idade > self.IDADE_LIMITE else self.FATOR_PADRAO
        return self.valor_base * fator

    def exibir_detalhes(self):
        """Estende a descrição base com a idade do segurado.

        Returns:
            str: Descrição completa do seguro de vida."""
        return f"{super().exibir_detalhes()} | Idade: {self.idade}"


class SeguroResidencial(Seguro):
    """Seguro residencial. O prêmio depende do tipo de imóvel.

    Attributes:
        tipo_imovel (str): ``"CASA"`` ou ``"APARTAMENTO"``."""

    FATOR_CASA = 1.15
    FATOR_APARTAMENTO = 1.05

    def __init__(self, titular, valor_base, tipo_imovel):
        """Cria um seguro residencial.

        Args:
            titular (Cliente): Cliente titular.
            valor_base (float): Valor base do seguro.
            tipo_imovel (str): ``"CASA"`` ou ``"APARTAMENTO"`` (sem diferenciar
                maiúsculas de minúsculas).

        Raises:
            ValueError: Se o tipo de imóvel for inválido."""
        tipo = tipo_imovel.strip().upper()
        if tipo not in ("CASA", "APARTAMENTO"):
            raise ValueError("tipo_imovel deve ser 'CASA' ou 'APARTAMENTO'.")
        super().__init__(titular, valor_base)
        self.tipo_imovel = tipo

    def calcular_premio(self):
        """Calcula o prêmio: casas pagam mais que apartamentos.

        Returns:
            float: ``valor_base * 1.15`` se casa; senão ``valor_base * 1.05``."""
        fator = self.FATOR_CASA if self.tipo_imovel == "CASA" else self.FATOR_APARTAMENTO
        return self.valor_base * fator

    def exibir_detalhes(self):
        """Estende a descrição base com o tipo de imóvel.

        Returns:
            str: Descrição completa do seguro residencial."""
        return f"{super().exibir_detalhes()} | Imóvel: {self.tipo_imovel.title()}"
