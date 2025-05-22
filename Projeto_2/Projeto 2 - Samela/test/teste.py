import sys
import os
sys.path.append(os.path.abspath('../src')) 

from cliente import Cliente, Carro, Modelo, Seguro

def test_classes():
    modelo = Modelo("Corolla")
    carro = Carro(2020, "Toyota", modelo, "Branco", "XYZ-1234")
    cliente = Cliente("João Silva", "123.456.789-00")
    seguro = Seguro(carro, cliente, 1500.0, "2024-01-01 a 2025-01-01")

    print("Informações do Cliente:")
    cliente.exibir_informacoes()

    print("\nDetalhes do Carro:")
    carro.exibir_detalhes()
    carro.atualizar_cor("Preto")
    carro.exibir_detalhes()

    print("\nValor do Seguro:")
    novo_valor = seguro.calcular_valor(1000.0, 0.1)
    print(f"Valor Calculado: R${novo_valor}")

    print("\nVigência válida?")
    print("Sim" if seguro.verificar_vigencia() else "Não")

if __name__ == "__main__":
    test_classes()
