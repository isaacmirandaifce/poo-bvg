"""
Módulo de hierarquia de seguros do sistema InsureTech Pro.

Define a classe abstrata base `Seguro` e as subclasses concretas
`SeguroAuto`, `SeguroVida` e `SeguroResidencial`, aplicando os
princípios de Herança, Polimorfismo e Abstração.
"""

from abc import ABC, abstractmethod
from datetime import date


class Seguro(ABC):
    """
    Classe abstrata base para todos os tipos de seguro.

    Define a interface comum que toda apólice deve implementar,
    incluindo os atributos compartilhados e o método abstrato
    `calcular_premio()`, que deve ser sobrescrito por cada subclasse.

    Attributes:
        _titular (str): Nome do titular da apólice.
        _valor_base (float): Valor base utilizado no cálculo do prêmio.
        _numero_apolice (str): Número identificador da apólice.
        _data_inicio (date): Data de início da vigência do seguro.
    """

    def __init__(
        self,
        titular: str,
        valor_base: float,
        numero_apolice: str,
        data_inicio: date = None,
    ):
        """
        Inicializa os atributos comuns a todos os seguros.

        Args:
            titular (str): Nome completo do titular da apólice.
            valor_base (float): Valor base (R$) para o cálculo do prêmio.
            numero_apolice (str): Código único que identifica a apólice.
            data_inicio (date, optional): Data de início da vigência.
                Padrão: data atual.
        """
        self._titular = titular
        self._valor_base = valor_base
        self._numero_apolice = numero_apolice
        self._data_inicio = data_inicio or date.today()

    # ------------------------------------------------------------------ #
    # Propriedades (encapsulamento com getters)                            #
    # ------------------------------------------------------------------ #

    @property
    def titular(self) -> str:
        """Retorna o nome do titular da apólice."""
        return self._titular

    @property
    def valor_base(self) -> float:
        """Retorna o valor base da apólice."""
        return self._valor_base

    @property
    def numero_apolice(self) -> str:
        """Retorna o número da apólice."""
        return self._numero_apolice

    @property
    def data_inicio(self) -> date:
        """Retorna a data de início da vigência."""
        return self._data_inicio

    # ------------------------------------------------------------------ #
    # Método abstrato — deve ser implementado pelas subclasses             #
    # ------------------------------------------------------------------ #

    @abstractmethod
    def calcular_premio(self) -> float:
        """
        Calcula e retorna o valor do prêmio da apólice.

        Cada subclasse aplica a regra de negócio específica ao seu
        tipo de seguro. O código cliente invoca este método sem precisar
        conhecer o tipo concreto do objeto (Polimorfismo).

        Returns:
            float: Valor do prêmio calculado em reais (R$).
        """

    # ------------------------------------------------------------------ #
    # Método auxiliar comum                                                #
    # ------------------------------------------------------------------ #

    def descricao(self) -> str:
        """
        Retorna uma descrição resumida da apólice.

        Returns:
            str: String com dados básicos e o prêmio calculado.
        """
        return (
            f"[{self.__class__.__name__}] "
            f"Apólice: {self._numero_apolice} | "
            f"Titular: {self._titular} | "
            f"Prêmio: R$ {self.calcular_premio():.2f}"
        )

    def __repr__(self) -> str:
        return (
            f"{self.__class__.__name__}("
            f"titular={self._titular!r}, "
            f"valor_base={self._valor_base}, "
            f"numero_apolice={self._numero_apolice!r})"
        )


# ======================================================================= #
# Subclasses concretas                                                     #
# ======================================================================= #


class SeguroAuto(Seguro):
    """
    Apólice de seguro para veículos automotores.

    Herda de `Seguro` e implementa `calcular_premio()` levando em conta
    o ano de fabricação do veículo: carros fabricados antes de 2010
    recebem fator 1,20 (maior risco); demais recebem fator 1,05.

    Attributes:
        _placa (str): Placa do veículo (dado sensível, protegido).
        _ano_fabricacao (int): Ano de fabricação do veículo.
        _modelo (str): Modelo/descrição do veículo.
    """

    def __init__(
        self,
        titular: str,
        valor_base: float,
        numero_apolice: str,
        placa: str,
        ano_fabricacao: int,
        modelo: str,
        data_inicio: date = None,
    ):
        """
        Inicializa uma apólice de seguro automotivo.

        Args:
            titular (str): Nome do titular.
            valor_base (float): Valor base para o cálculo do prêmio.
            numero_apolice (str): Número da apólice.
            placa (str): Placa do veículo (armazenada de forma protegida).
            ano_fabricacao (int): Ano de fabricação do veículo.
            modelo (str): Modelo do veículo (ex.: "Honda Civic").
            data_inicio (date, optional): Data de início da vigência.
        """
        super().__init__(titular, valor_base, numero_apolice, data_inicio)
        self._placa = placa          # dado sensível — acesso controlado
        self._ano_fabricacao = ano_fabricacao
        self._modelo = modelo

    # Propriedade para acesso controlado à placa (dado sensível)
    @property
    def placa_mascarada(self) -> str:
        """Retorna a placa parcialmente mascarada (ex.: 'AB***-1234')."""
        p = self._placa.replace("-", "").replace(" ", "")
        return f"{p[:2]}***-{p[-4:]}" if len(p) >= 6 else "***"

    @property
    def ano_fabricacao(self) -> int:
        """Retorna o ano de fabricação do veículo."""
        return self._ano_fabricacao

    @property
    def modelo(self) -> str:
        """Retorna o modelo do veículo."""
        return self._modelo

    def calcular_premio(self) -> float:
        """
        Calcula o prêmio do seguro automotivo.

        Regra de negócio:
            - Veículos fabricados antes de 2010 → fator 1,20 (maior risco).
            - Veículos a partir de 2010 → fator 1,05.

        Returns:
            float: Valor do prêmio em reais.
        """
        fator = 1.20 if self._ano_fabricacao < 2010 else 1.05
        return self._valor_base * fator

    def descricao(self) -> str:
        base = super().descricao()
        return f"{base} | Veículo: {self._modelo} ({self._ano_fabricacao}) | Placa: {self.placa_mascarada}"


class SeguroVida(Seguro):
    """
    Apólice de seguro de vida.

    Implementa `calcular_premio()` com base na idade do segurado:
    titulares acima de 60 anos têm fator 2,00; demais têm fator 1,10.

    Attributes:
        _cpf (str): CPF do segurado (dado sensível, protegido).
        _idade (int): Idade atual do segurado em anos.
        _beneficiario (str): Nome do beneficiário da apólice.
    """

    def __init__(
        self,
        titular: str,
        valor_base: float,
        numero_apolice: str,
        cpf: str,
        idade: int,
        beneficiario: str,
        data_inicio: date = None,
    ):
        """
        Inicializa uma apólice de seguro de vida.

        Args:
            titular (str): Nome do titular.
            valor_base (float): Valor base para o cálculo do prêmio.
            numero_apolice (str): Número da apólice.
            cpf (str): CPF do segurado (armazenado de forma protegida).
            idade (int): Idade do segurado em anos completos.
            beneficiario (str): Nome do beneficiário.
            data_inicio (date, optional): Data de início da vigência.
        """
        super().__init__(titular, valor_base, numero_apolice, data_inicio)
        self._cpf = cpf              # dado sensível — acesso controlado
        self._idade = idade
        self._beneficiario = beneficiario

    @property
    def cpf_mascarado(self) -> str:
        """Retorna o CPF parcialmente mascarado (ex.: '***.***.789-00')."""
        digitos = self._cpf.replace(".", "").replace("-", "").replace(" ", "")
        if len(digitos) == 11:
            return f"***.***. {digitos[6:9]}-{digitos[9:]}"
        return "***"

    @property
    def idade(self) -> int:
        """Retorna a idade do segurado."""
        return self._idade

    @property
    def beneficiario(self) -> str:
        """Retorna o nome do beneficiário."""
        return self._beneficiario

    def calcular_premio(self) -> float:
        """
        Calcula o prêmio do seguro de vida.

        Regra de negócio:
            - Segurados com mais de 60 anos → fator 2,00 (maior risco).
            - Demais segurados → fator 1,10.

        Returns:
            float: Valor do prêmio em reais.
        """
        fator = 2.00 if self._idade > 60 else 1.10
        return self._valor_base * fator

    def descricao(self) -> str:
        base = super().descricao()
        return f"{base} | Idade: {self._idade} anos | Beneficiário: {self._beneficiario}"


class SeguroResidencial(Seguro):
    """
    Apólice de seguro residencial.

    Implementa `calcular_premio()` considerando o tipo de imóvel:
    casas têm fator 1,15; apartamentos têm fator 1,05.

    Attributes:
        _tipo_imovel (str): Tipo do imóvel — "CASA" ou "APARTAMENTO".
        _endereco (str): Endereço do imóvel segurado.
        _area_m2 (float): Área do imóvel em metros quadrados.
    """

    TIPOS_VALIDOS = {"CASA", "APARTAMENTO"}

    def __init__(
        self,
        titular: str,
        valor_base: float,
        numero_apolice: str,
        tipo_imovel: str,
        endereco: str,
        area_m2: float,
        data_inicio: date = None,
    ):
        """
        Inicializa uma apólice de seguro residencial.

        Args:
            titular (str): Nome do titular.
            valor_base (float): Valor base para o cálculo do prêmio.
            numero_apolice (str): Número da apólice.
            tipo_imovel (str): "CASA" ou "APARTAMENTO".
            endereco (str): Endereço completo do imóvel.
            area_m2 (float): Área do imóvel em m².
            data_inicio (date, optional): Data de início da vigência.

        Raises:
            ValueError: Se `tipo_imovel` não for "CASA" ou "APARTAMENTO".
        """
        tipo_upper = tipo_imovel.upper()
        if tipo_upper not in self.TIPOS_VALIDOS:
            raise ValueError(
                f"tipo_imovel deve ser um de {self.TIPOS_VALIDOS}; "
                f"recebido: {tipo_imovel!r}"
            )
        super().__init__(titular, valor_base, numero_apolice, data_inicio)
        self._tipo_imovel = tipo_upper
        self._endereco = endereco
        self._area_m2 = area_m2

    @property
    def tipo_imovel(self) -> str:
        """Retorna o tipo do imóvel ('CASA' ou 'APARTAMENTO')."""
        return self._tipo_imovel

    @property
    def endereco(self) -> str:
        """Retorna o endereço do imóvel."""
        return self._endereco

    @property
    def area_m2(self) -> float:
        """Retorna a área do imóvel em m²."""
        return self._area_m2

    def calcular_premio(self) -> float:
        """
        Calcula o prêmio do seguro residencial.

        Regra de negócio:
            - Imóvel do tipo CASA → fator 1,15 (maior exposição a riscos).
            - Imóvel do tipo APARTAMENTO → fator 1,05.

        Returns:
            float: Valor do prêmio em reais.
        """
        fator = 1.15 if self._tipo_imovel == "CASA" else 1.05
        return self._valor_base * fator

    def descricao(self) -> str:
        base = super().descricao()
        return f"{base} | Tipo: {self._tipo_imovel} | Área: {self._area_m2} m²"
