from models.cliente import Cliente
from models.seguros import SeguroAuto, SeguroVida, SeguroResidencial


def main():
    # criando clientes
    cliente1 = Cliente("Gabriel", "123.456.789-00")
    cliente2 = Cliente("Maria", "987.654.321-00")

    # lista de seguros (polimorfismo)
    seguros = [
        SeguroAuto(cliente1, 1000, 2008),
        SeguroAuto(cliente2, 1000, 2015),
        SeguroVida(cliente1, 500, 65),
        SeguroVida(cliente2, 500, 30),
        SeguroResidencial(cliente1, 800, "CASA"),
        SeguroResidencial(cliente2, 800, "APARTAMENTO"),
    ]

    # cálculo dos prêmios
    for seguro in seguros:
        print(f"Cliente: {seguro.titular.nome}")
        print(f"Prêmio: R$ {seguro.calcular_premio():.2f}")
        print("-" * 20)


if __name__ == "__main__":
    main()