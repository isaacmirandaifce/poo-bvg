"""
 — Sistema de Seguros de Veículos
"""

from datetime import date


# ══════════════════════════════════════════════════════════════════════════════
# Classes de domínio (Exercícios 1 e 2)
# ══════════════════════════════════════════════════════════════════════════════

class Modelo:
    """Representa o modelo de um veículo (ex.: Corolla, Civic)."""

    def __init__(self, nome: str):
        self.nome = nome

    def __str__(self):
        return self.nome


class Carro:
    """
    Representa um carro.

    Encapsulamento (Exercício 6):
      - 'placa' é privado (__placa).
      - Acesso apenas via get_placa().
    """

    def __init__(self, ano: int, marca: str, modelo: Modelo,
                 cor: str, placa: str):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.__placa = placa          # atributo privado

    # --- acesso controlado ---
    def get_placa(self) -> str:
        """Retorna a placa do carro."""
        return self.__placa

    # --- métodos públicos ---
    def exibir_detalhes(self):
        """Exibe as informações do carro."""
        print(f"  Carro  : {self.marca} {self.modelo} ({self.ano})")
        print(f"  Cor    : {self.cor}")
        print(f"  Placa  : {self.__placa}")

    def atualizar_cor(self, nova_cor: str):
        """Modifica a cor do carro."""
        self.cor = nova_cor
        print(f"  Cor atualizada para: {nova_cor}")


class Cliente:
    """
    Representa um cliente da seguradora.

    Encapsulamento (Exercício 6):
      - 'cpf' é privado (__cpf).
      - Acesso apenas via get_cpf(), que retorna o CPF mascarado.
    """

    def __init__(self, nome: str, cpf: str):
        self.nome = nome
        self.__cpf = cpf              # atributo privado

    # --- acesso controlado ---
    def get_cpf(self) -> str:
        """Retorna o CPF mascarado (somente últimos 6 dígitos visíveis)."""
        return f"***{self.__cpf[-6:]}"

    def get_nome(self) -> str:
        return self.nome

    # --- métodos públicos ---
    def exibir_informacoes(self):
        """Exibe o nome e o CPF do cliente."""
        print(f"  Nome : {self.nome}")
        print(f"  CPF  : {self.get_cpf()}")


# ══════════════════════════════════════════════════════════════════════════════
# Hierarquia de seguros — Herança (Exercício 4)
# ══════════════════════════════════════════════════════════════════════════════

class SeguroVeiculo:
    """
    Classe base para todos os seguros de veículos.

    Benefício da herança (Exercício 4b):
      - Atributos e métodos comuns ficam aqui uma única vez.
      - Subclasses herdam e só sobrescrevem o que é específico.
      - Permite tratar SeguroCarro e SeguroMoto de forma polimórfica.
    """

    def __init__(self, cliente: "Cliente", valor: float,
                 vigencia_inicio: date, vigencia_fim: date):
        self._cliente = cliente
        self._valor = valor
        self._vigencia_inicio = vigencia_inicio
        self._vigencia_fim = vigencia_fim

    def get_valor(self) -> float:
        return self._valor

    def verificar_vigencia(self) -> bool:
        """
        Exercício 6b — Pseudocódigo implementado:

          hoje ← data_atual()
          se vigencia_inicio ≤ hoje E hoje ≤ vigencia_fim:
              retornar VERDADEIRO
          senão:
              retornar FALSO
        """
        hoje = date.today()
        return self._vigencia_inicio <= hoje <= self._vigencia_fim

    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        """
        Exercício 4c — Implementação base:
          valor = base_valor × (1 + taxa)
        Subclasses sobrescrevem este método para cálculos específicos.
        """
        self._valor = base_valor * (1 + taxa)
        return self._valor

    def exibir_resumo(self):
        status = "ATIVO" if self.verificar_vigencia() else "VENCIDO"
        print(f"  Valor    : R$ {self._valor:,.2f}")
        print(f"  Vigência : {self._vigencia_inicio} a {self._vigencia_fim}")
        print(f"  Status   : {status}")


class Seguro(SeguroVeiculo):
    """
    Seguro de carro — uso geral (Exercícios 1, 2, 3).

    Relacionamentos:
      - Seguro ↔ Carro   : AGREGAÇÃO (Exercício 3b)
          O Carro existe independentemente do Seguro.
          O Seguro apenas referencia os carros.
      - Seguro ↔ Cliente : ASSOCIAÇÃO SIMPLES (Exercício 1c)
          O Cliente existe antes e depois do Seguro.

    Multiplicidade (Exercício 3a):
      Um Seguro pode ter uma lista de Carros (1..*).
    """

    def __init__(self, cliente: Cliente, valor: float,
                 vigencia_inicio: date, vigencia_fim: date):
        super().__init__(cliente, valor, vigencia_inicio, vigencia_fim)
        self._carros: list[Carro] = []   # agregação com múltiplos carros

    def adicionar_carro(self, carro: Carro):
        """Exercício 3a: associa mais um Carro ao Seguro."""
        self._carros.append(carro)

    def listar_carros(self) -> list[Carro]:
        return self._carros

    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        """
        Exercício 4c — Sobrescrita: aplica +10% por carro extra.
        """
        fator = 1 + (len(self._carros) - 1) * 0.10
        self._valor = base_valor * (1 + taxa) * fator
        return self._valor

    def exibir_detalhes(self):
        print(f"  Cliente : {self._cliente.get_nome()}")
        for i, carro in enumerate(self._carros, 1):
            print(f"  Carro {i}:")
            carro.exibir_detalhes()
        self.exibir_resumo()


class SeguroCarro(SeguroVeiculo):
    """
    Exercício 4 — Herda de SeguroVeiculo.
    Atributos específicos de seguro de carro: franquia e cobertura a terceiros.
    """

    def __init__(self, cliente: Cliente, valor: float,
                 vigencia_inicio: date, vigencia_fim: date,
                 franquia: float = 0.0, cobre_terceiros: bool = False):
        super().__init__(cliente, valor, vigencia_inicio, vigencia_fim)
        self._carros: list[Carro] = []
        self.franquia = franquia
        self.cobre_terceiros = cobre_terceiros

    def adicionar_carro(self, carro: Carro):
        self._carros.append(carro)

    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        """
        Exercício 4c — Sobrescrita:
          + 5% se cobre terceiros.
        """
        extra = 0.05 if self.cobre_terceiros else 0.0
        self._valor = base_valor * (1 + taxa + extra)
        return self._valor


class SeguroMoto(SeguroVeiculo):
    """
    Exercício 4 — Herda de SeguroVeiculo.
    Atributos específicos de seguro de moto: cilindradas e capacete.
    """

    def __init__(self, cliente: Cliente, valor: float,
                 vigencia_inicio: date, vigencia_fim: date,
                 cilindradas: int = 150, capacete_incluso: bool = False):
        super().__init__(cliente, valor, vigencia_inicio, vigencia_fim)
        self.cilindradas = cilindradas
        self.capacete_incluso = capacete_incluso

    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        """
        Exercício 4c — Sobrescrita:
          + 15% de risco extra para motos acima de 600cc.
        """
        risco = 0.15 if self.cilindradas > 600 else 0.0
        self._valor = base_valor * (1 + taxa + risco)
        return self._valor

    def verificar_cilindradas(self) -> str:
        if self.cilindradas > 600:
            return "Alta cilindrada (risco elevado)"
        return "Cilindrada padrão"

    def get_capacete(self) -> bool:
        return self.capacete_incluso
