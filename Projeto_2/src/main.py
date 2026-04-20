from models.cliente import Cliente
from models.seguros import SeguroAuto, SeguroVida, SeguroResidencial

def main():
    cliente = Cliente("João", "123.456.789-00")

    s1 = SeguroAuto(cliente.nome, 1000, 2005)
    s2 = SeguroVida(cliente.nome, 800, 65)
    s3 = SeguroResidencial(cliente.nome, 500, "CASA")

    cliente.adicionar_seguro(s1)
    cliente.adicionar_seguro(s2)
    cliente.adicionar_seguro(s3)

    print("=== Seguros do Cliente ===")
    for seguro in cliente.listar_seguros():
        print(f"Prêmio: R$ {seguro.calcular_premio()}")

if __name__ == "__main__":
    main()