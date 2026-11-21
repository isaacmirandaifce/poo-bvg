
from models.cliente import Cliente
from models.seguros import (
    SeguroAuto,
    SeguroVida,
    SeguroResidencial,
)


def main():

    cliente = Cliente("Danilo Vieira", "65574568900")

    seguro_auto = SeguroAuto(
        cliente, 1000.0, "THY1D09", 2013
    )

    seguro_vida = SeguroVida(
        cliente, 500.0, 65
    )

    seguro_residencial = SeguroResidencial(
        cliente, 800.0, "CASA"
    )

    cliente.adicionarSeguro(seguro_auto)
    cliente.adicionarSeguro(seguro_vida)
    cliente.adicionarSeguro(seguro_residencial)

    print(f"Cliente: {cliente.nome}")
    print(f"CPF: {cliente.cpf}")
    print("-" * 40)

    total = 0.0

    for seguro in cliente.seguros:
        premio = seguro.calcular_premio()

        print(f"Tipo: {type(seguro).__name__}")
        print(f"Prêmio: R$ {premio:.2f}")
        print("-" * 40)

        total += premio

    print(f"Total dos prêmios: R$ {total:.2f}")


if __name__ == "__main__":
    main()
