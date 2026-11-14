"""Demonstração de polimorfismo no subsistema de seguros."""

from models.cliente import Cliente
from models.seguros import SeguroAuto, SeguroResidencial, SeguroVida

def main():
    """Cria seguros variados e percorre a lista chamando ``calcular_premio()``.

    Note que não há nenhum ``if/else`` para descobrir o tipo de seguro: cada
    objeto responde com o prêmio correto (polimorfismo)."""
    joao = Cliente("João Silva", "123.456.789-00")
    maria = Cliente("Maria Souza", "987.654.321-00")

    seguros = [
        SeguroAuto(joao, 1500.00, "Toyota Corolla", 2020, "XYZ-1234"),
        SeguroAuto(joao, 1500.00, "Fiat Uno", 2005, "ABC-9876"),
        SeguroVida(maria, 800.00, 35),
        SeguroVida(maria, 800.00, 65),
        SeguroResidencial(joao, 1200.00, "CASA"),
        SeguroResidencial(maria, 1200.00, "APARTAMENTO"),
    ]

    print("=== Prêmios (polimorfismo) ===")
    for seguro in seguros:
        print(seguro.exibir_detalhes())

    print("\n=== Total por cliente ===")
    for cliente in (joao, maria):
        print(
            f"{cliente.exibir_informacoes()} -> {len(cliente.seguros)} seguros, "
            f"total R${cliente.calcular_total_premios():.2f}"
        )


if __name__ == "__main__":
    main()
