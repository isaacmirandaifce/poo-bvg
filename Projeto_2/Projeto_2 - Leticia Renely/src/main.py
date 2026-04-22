from models.cliente import Cliente
from models.seguros import SeguroAuto, SeguroVida, SeguroResidencial


def main():
    cliente1 = Cliente("Laylla", "123.456.789-00")
    cliente2 = Cliente("José", "987.654.321-00")

    seguros = [
        SeguroAuto(cliente1, 1000, 2008),
        SeguroVida(cliente2, 1500, 65),
        SeguroResidencial(cliente1, 2000, "CASA")
    ]

    for seguro in seguros:
        print(f"Cliente: {seguro._titular.get_nome()} | Prêmio: R$ {seguro.calcular_premio():.2f}")


if __name__ == "__main__":
    main()