import sys
import os
sys.path.append(os.path.abspath('../src'))

from cliente import Cliente, Carro, Modelo, Seguro

def test_classes():
    modelo = Modelo("Corolla")
    carro = Carro(2020, "Toyota", modelo, "Branco", "XYZ-1234")
    cliente = Cliente("João Silva", "123.456.789-00")
    seguro = Seguro(carro, cliente, 1500.0, "ativa")

    print("Informações do Cliente:")
    cliente.exibir_informacoes()

    print("\nDetalhes do Carro:")
    carro.exibir_detalhes()

    carro.atualizar_cor("Prata")
    print("\nDetalhes do Carro após mudança de cor:")
    carro.exibir_detalhes()

    print("\nValor do seguro calculado:", seguro.calcular_valor(1500, 0.05))
    print("Seguro está vigente?", seguro.verificar_vigencia())

    print("\nCPF (via get):", cliente.get_cpf())
    print("Placa (via get):", carro.get_placa())

# Chama o teste
if __name__ == "__main__":
    test_classes()
