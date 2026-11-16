from models.cliente import Cliente
from models.seguros import Seguro, SeguroAuto, SeguroVida, SeguroResidencial


def main():
    """Demonstra o polimorfismo no cálculo de prêmios."""
    ana = Cliente("Ana Souza", "12345678901")
    joao = Cliente("João Lima", "98765432100")

    seguros = [
        SeguroAuto(ana, 12000, modelo="Hilux SW4 Diamond", ano=2026, placa="SWD4E26"),
        SeguroAuto(joao, 1000, modelo="Gol", ano=2008, placa="ABC1D23"),
        SeguroVida(ana, 1000, idade=65),
        SeguroResidencial(joao, 1000, tipo_imovel="CASA"),
    ]

    for seguro in seguros:
        print(f"{seguro}: R$ {seguro.calcular_premio():.2f}")

    try:
        Seguro(ana, 1000)
    except TypeError as erro:
        print(f"Abstração funcionando: {erro}")


if __name__ == "__main__":
    main()