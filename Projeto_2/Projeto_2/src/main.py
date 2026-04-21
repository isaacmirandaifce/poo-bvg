import sys
import os

sys.path.insert(0, os.path.dirname(__file__) + "/..")

from src.models.cliente import Cliente
from src.models.seguros import Seguro, SeguroAuto, SeguroVida, SeguroResidencial


def exibir_separador(titulo: str) -> None:
    largura = 60
    print("\n" + "=" * largura)
    print(f"  {titulo}")
    print("=" * largura)


def processar_seguros(lista_seguros: list[Seguro]) -> None:
    for seguro in lista_seguros:
        print(f"\n  Tipo     : {type(seguro).__name__}")
        print(f"  Titular  : {seguro._titular.get_nome()}")
        print(f"  Apólice  : {seguro._numero_apolice}")
        print(f"  Prêmio   : R$ {seguro.calcular_premio():.2f}")
        print(f"  Info     : {seguro.get_info()}")
        print("  " + "-" * 55)


def main() -> None:
    exibir_separador("CRIANDO CLIENTES")

    alice = Cliente("Alice Souza", "111.222.333-44", "alice@email.com")
    bob = Cliente("Bob Ferreira", "555.666.777-88", "bob@email.com")
    carol = Cliente("Carol Lima", "999.000.111-22", "carol@email.com")
    diana = Cliente("Diana Reis", "333.444.555-66", "diana@email.com")

    for cliente in [alice, bob, carol, diana]:
        print(f"  {cliente}")

    exibir_separador("INSTANCIANDO SEGUROS")

    auto_velho = SeguroAuto(
        titular=alice,
        valor_base=2000.00,
        numero_apolice="AUTO-001",
        placa="ABC-1234",
        ano_fabricacao=2005,
        modelo="Fiat Uno",
    )

    auto_novo = SeguroAuto(
        titular=bob,
        valor_base=3500.00,
        numero_apolice="AUTO-002",
        placa="XYZ-9999",
        ano_fabricacao=2022,
        modelo="Honda Civic",
    )

    vida_jovem = SeguroVida(
        titular=carol,
        valor_base=1500.00,
        numero_apolice="VIDA-001",
        idade_segurado=35,
        cobertura="Morte e invalidez",
    )

    vida_senior = SeguroVida(
        titular=diana,
        valor_base=1500.00,
        numero_apolice="VIDA-002",
        idade_segurado=65,
        cobertura="Morte, invalidez e doenças graves",
    )

    residencial_casa = SeguroResidencial(
        titular=alice,
        valor_base=4000.00,
        numero_apolice="RESID-001",
        tipo_imovel="CASA",
        endereco="Rua das Flores, 10",
        area_m2=200.0,
    )

    residencial_apto = SeguroResidencial(
        titular=bob,
        valor_base=2500.00,
        numero_apolice="RESID-002",
        tipo_imovel="APARTAMENTO",
        endereco="Av. Central, 500 — Apto 32",
        area_m2=80.0,
    )

    lista_de_seguros: list[Seguro] = [
        auto_velho,
        auto_novo,
        vida_jovem,
        vida_senior,
        residencial_casa,
        residencial_apto,
    ]

    exibir_separador("CALCULANDO PRÊMIOS (Polimorfismo)")
    print("  → Chamando seguro.calcular_premio() sem nenhum if/else!\n")
    processar_seguros(lista_de_seguros)

    exibir_separador("RESUMO — CÓDIGO LEGADO vs. SOLUÇÃO OO")
    exibir_separador("ENCAPSULAMENTO — Dados sensíveis protegidos")
    print(f"  CPF de Alice (mascarado): {alice.get_cpf_mascarado()}")
    print(f"  Placa do auto_velho: {auto_velho.get_placa()}")
    print()
    print("  Tentando acessar CPF diretamente geraria AttributeError:")
    print("    alice.__cpf  →  AttributeError: 'Cliente' object has no attribute '__cpf'")


if __name__ == "__main__":
    main()
