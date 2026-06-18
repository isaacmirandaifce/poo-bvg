"""
Módulo que define a entidade Cliente do sistema InsureTech Pro.

Um Cliente pode possuir zero ou mais apólices de seguro (associação
de composição 1..* no diagrama UML). Os dados sensíveis (CPF, e-mail)
são armazenados de forma protegida e expostos apenas via propriedades.
"""

from __future__ import annotations
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from models.seguros import Seguro


class Cliente:
    """
    Representa um cliente que pode contratar apólices de seguro.

    Mantém uma lista interna de seguros associados e fornece métodos
    para adicionar apólices e calcular o total de prêmios a pagar.

    Attributes:
        _nome (str): Nome completo do cliente.
        _cpf (str): CPF do cliente (dado sensível, protegido).
        _email (str): E-mail do cliente (dado sensível, protegido).
        _telefone (str): Telefone de contato.
        _seguros (list[Seguro]): Lista de apólices vinculadas ao cliente.
    """

    def __init__(
        self,
        nome: str,
        cpf: str,
        email: str,
        telefone: str = "",
    ):
        """
        Inicializa um novo cliente.

        Args:
            nome (str): Nome completo do cliente.
            cpf (str): CPF do cliente (armazenado de forma protegida).
            email (str): E-mail do cliente (armazenado de forma protegida).
            telefone (str, optional): Telefone de contato. Padrão: "".
        """
        self._nome = nome
        self._cpf = cpf          # dado sensível
        self._email = email      # dado sensível
        self._telefone = telefone
        self._seguros: list[Seguro] = []

    # ------------------------------------------------------------------ #
    # Propriedades                                                         #
    # ------------------------------------------------------------------ #

    @property
    def nome(self) -> str:
        """Retorna o nome do cliente."""
        return self._nome

    @property
    def cpf_mascarado(self) -> str:
        """Retorna o CPF parcialmente mascarado (ex.: '***.456.***-00')."""
        digitos = self._cpf.replace(".", "").replace("-", "").replace(" ", "")
        if len(digitos) == 11:
            return f"***.{digitos[3:6]}.***-{digitos[9:]}"
        return "***"

    @property
    def email_mascarado(self) -> str:
        """Retorna o e-mail com o usuário parcialmente oculto."""
        partes = self._email.split("@")
        if len(partes) == 2:
            usuario = partes[0]
            visivel = usuario[:2] if len(usuario) > 2 else usuario[0]
            return f"{visivel}***@{partes[1]}"
        return "***"

    @property
    def telefone(self) -> str:
        """Retorna o telefone de contato."""
        return self._telefone

    @property
    def seguros(self) -> list:
        """Retorna uma cópia da lista de apólices do cliente."""
        return list(self._seguros)

    # ------------------------------------------------------------------ #
    # Métodos de negócio                                                   #
    # ------------------------------------------------------------------ #

    def adicionar_seguro(self, seguro: "Seguro") -> None:
        """
        Vincula uma nova apólice de seguro ao cliente.

        Args:
            seguro (Seguro): Instância de qualquer subclasse concreta de
                `Seguro` a ser associada a este cliente.
        """
        self._seguros.append(seguro)

    def total_premios(self) -> float:
        """
        Calcula a soma dos prêmios de todas as apólices do cliente.

        Demonstra Polimorfismo: itera sobre seguros de tipos diferentes
        e chama `.calcular_premio()` sem distinguir qual subclasse é qual.

        Returns:
            float: Soma total dos prêmios em reais.
        """
        return sum(s.calcular_premio() for s in self._seguros)

    def relatorio(self) -> str:
        """
        Gera um relatório textual com todas as apólices do cliente.

        Returns:
            str: Texto formatado com dados do cliente e suas apólices.
        """
        linhas = [
            "=" * 60,
            f"  CLIENTE: {self._nome}",
            f"  CPF   : {self.cpf_mascarado}",
            f"  E-mail: {self.email_mascarado}",
            "=" * 60,
        ]
        if not self._seguros:
            linhas.append("  Nenhuma apólice cadastrada.")
        else:
            for i, seguro in enumerate(self._seguros, start=1):
                linhas.append(f"  [{i}] {seguro.descricao()}")
            linhas.append("-" * 60)
            linhas.append(f"  TOTAL DE PRÊMIOS: R$ {self.total_premios():.2f}")
        linhas.append("=" * 60)
        return "\n".join(linhas)

    def __repr__(self) -> str:
        return (
            f"Cliente(nome={self._nome!r}, "
            f"cpf={self.cpf_mascarado!r}, "
            f"n_seguros={len(self._seguros)})"
        )
