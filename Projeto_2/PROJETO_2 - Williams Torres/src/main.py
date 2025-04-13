from cliente import Cliente
from carro import Carro
from seguro import SeguroCarro

def main():
    # Criando um cliente
    cliente = Cliente("João Silva", "123.456.789-00")

    # Criando um carro
    carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")

    # Criando um seguro para o carro
    seguro = SeguroCarro(cliente, carro, 1500.00, "2024-01-01 a 2025-01-01")

    # Exibindo os detalhes do seguro
    print(seguro.exibir_detalhes())

    # Atualizando a cor do carro
    carro.atualizar_cor("Preto")
    print(f"Carro atualizado: {carro.exibir_detalhes()}")

    # Verificando vigência
    print("Seguro válido:", seguro.verificar_vigencia("2024-06-15"))

if __name__ == "__main__":
    main()
