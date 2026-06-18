import sys
import os

# Garante que o diretório 'src' esteja no path para importações relativas
sys.path.insert(0, os.path.dirname(__file__))

from datetime import date
from models.seguros import SeguroAuto, SeguroVida, SeguroResidencial
from models.cliente import Cliente


def separador(titulo: str = "", largura: int = 60) -> None:
    """Imprime um separador visual no console."""
    if titulo:
        print(f"\n{'─' * 4} {titulo} {'─' * (largura - len(titulo) - 6)}")
    else:
        print("─" * largura)


def demonstrar_polimorfismo(seguros: list) -> None:
    """
    Demonstração central de Polimorfismo.

    Percorre uma lista com tipos diferentes de seguro e chama
    `.calcular_premio()` sem nenhum if/else condicional sobre o tipo.
    O método correto é despachado automaticamente pelo Python com base
    no tipo real do objeto em tempo de execução.

    Args:
        seguros (list): Lista contendo instâncias de subclasses de Seguro.
    """
    separador("DEMONSTRAÇÃO DE POLIMORFISMO")
    print(
        "  Iterando sobre seguros de tipos distintos e chamando\n"
        "  .calcular_premio() sem nenhum if/else de tipo:\n"
    )

    total = 0.0
    for seguro in seguros:
        premio = seguro.calcular_premio()   # ← Polimorfismo aqui!
        total += premio
        print(f"  • {type(seguro).__name__:<22} → R$ {premio:>10.2f}")

    separador()
    print(f"  Total geral de prêmios: R$ {total:.2f}")


def criar_clientes_e_seguros() -> list[Cliente]:
    """
    Cria clientes de exemplo com apólices variadas.

    Returns:
        list[Cliente]: Lista de clientes com seguros associados.
    """
    # ── Cliente 1: Maria Fernanda ────────────────────────────────────── #
    maria = Cliente(
        nome="Maria Fernanda Souza",
        cpf="123.456.789-00",
        email="mariafernanda@email.com",
        telefone="(85) 91234-5678",
    )
    maria.adicionar_seguro(
        SeguroAuto(
            titular="Maria Fernanda Souza",
            valor_base=1_500.00,
            numero_apolice="AUTO-2024-001",
            placa="ABC-1234",
            ano_fabricacao=2007,          # < 2010 → fator 1.20
            modelo="Toyota Corolla",
            data_inicio=date(2024, 1, 15),
        )
    )
    maria.adicionar_seguro(
        SeguroResidencial(
            titular="Maria Fernanda Souza",
            valor_base=800.00,
            numero_apolice="RES-2024-001",
            tipo_imovel="CASA",           # fator 1.15
            endereco="Rua das Flores, 42 — Fortaleza/CE",
            area_m2=120.0,
            data_inicio=date(2024, 1, 15),
        )
    )

    # ── Cliente 2: João Carlos ───────────────────────────────────────── #
    joao = Cliente(
        nome="João Carlos Pereira",
        cpf="987.654.321-11",
        email="joaocarlos@provedor.net",
        telefone="(85) 99876-5432",
    )
    joao.adicionar_seguro(
        SeguroVida(
            titular="João Carlos Pereira",
            valor_base=2_000.00,
            numero_apolice="VIDA-2024-001",
            cpf="987.654.321-11",
            idade=65,                     # > 60 → fator 2.00
            beneficiario="Ana Paula Pereira",
            data_inicio=date(2024, 3, 1),
        )
    )
    joao.adicionar_seguro(
        SeguroAuto(
            titular="João Carlos Pereira",
            valor_base=1_200.00,
            numero_apolice="AUTO-2024-002",
            placa="XYZ-9876",
            ano_fabricacao=2022,          # ≥ 2010 → fator 1.05
            modelo="Hyundai HB20",
            data_inicio=date(2024, 3, 1),
        )
    )

    # ── Cliente 3: Beatriz Alves ─────────────────────────────────────── #
    beatriz = Cliente(
        nome="Beatriz Alves Lima",
        cpf="555.111.222-33",
        email="beatriz.lima@empresa.com",
        telefone="(85) 98765-0001",
    )
    beatriz.adicionar_seguro(
        SeguroVida(
            titular="Beatriz Alves Lima",
            valor_base=1_800.00,
            numero_apolice="VIDA-2024-002",
            cpf="555.111.222-33",
            idade=35,                     # ≤ 60 → fator 1.10
            beneficiario="Carlos Lima",
            data_inicio=date(2024, 6, 1),
        )
    )
    beatriz.adicionar_seguro(
        SeguroResidencial(
            titular="Beatriz Alves Lima",
            valor_base=600.00,
            numero_apolice="RES-2024-002",
            tipo_imovel="APARTAMENTO",    # fator 1.05
            endereco="Av. Beira Mar, 500, Apto 303 — Fortaleza/CE",
            area_m2=75.0,
            data_inicio=date(2024, 6, 1),
        )
    )

    return [maria, joao, beatriz]


def main() -> None:
    """
    Função principal do sistema InsureTech Pro.

    Fluxo:
        1. Cria clientes com apólices de tipos variados.
        2. Demonstra polimorfismo iterando sobre lista heterogênea.
        3. Exibe relatórios individuais por cliente.
        4. Exibe resumo global do sistema.
    """
    print("\n" + "═" * 60)
    print("       InsureTech Pro — Sistema de Gestão de Seguros")
    print("═" * 60)

    clientes = criar_clientes_e_seguros()

    # ── 1. Coleta todos os seguros em uma lista heterogênea ─────────── #
    todos_seguros = []
    for cliente in clientes:
        todos_seguros.extend(cliente.seguros)

    # ── 2. Polimorfismo puro: sem if/else de tipo ────────────────────── #
    demonstrar_polimorfismo(todos_seguros)

    # ── 3. Relatórios por cliente ─────────────────────────────────────── #
    separador("RELATÓRIOS POR CLIENTE")
    for cliente in clientes:
        print(cliente.relatorio())
        print()

    # ── 4. Resumo global ─────────────────────────────────────────────── #
    separador("RESUMO GLOBAL DO SISTEMA")
    total_sistema = sum(s.calcular_premio() for s in todos_seguros)
    print(f"  Clientes ativos       : {len(clientes)}")
    print(f"  Apólices emitidas     : {len(todos_seguros)}")
    print(f"  Receita total (prêm.) : R$ {total_sistema:.2f}")
    separador()

    print(
        "\n  [OK] Nenhum if/else sobre tipo de seguro foi utilizado no\n"
        "  código cliente. O Polimorfismo despachou o método correto\n"
        "  automaticamente para cada objeto da lista.\n"
    )


if __name__ == "__main__":
    main()
