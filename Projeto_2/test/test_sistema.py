import sys
sys.path.insert(0, "../src")

from datetime import date
from cliente import Cliente
from carro import Carro
from seguro import SeguroCarro, SeguroMoto

def test_carro():
    carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
    assert carro.ano == 2020
    assert carro.cor == "Branco"

    carro.atualizar_cor("Vermelho")
    assert carro.cor == "Vermelho"

    assert carro.get_placa() == "XYZ-1234"
    print("test_carro OK")

def test_cliente():
    cliente = Cliente("Davi Maciel", "123.456.789-00")
    assert cliente.nome == "Davi Maciel"
    assert cliente.get_cpf() == "123.456.789-00"
    print("test_cliente OK")

def test_seguro_carro():
    cliente = Cliente("Davi Maciel", "123.456.789-00")
    carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
    seguro = SeguroCarro(cliente, carro, 0, date(2026, 1, 1), date(2027, 1, 1))

    valor = seguro.calcular_valor(1500, 0.10)
    assert round(valor, 2) == 1725.0

    assert seguro.verificar_vigencia() == True
    print("test_seguro_carro OK")

def test_seguro_moto():
    cliente = Cliente("Nágilla", "000.000.000-00")
    moto = Carro(2022, "Yamaha", "MT-07", "Preta", "MOT-9999")
    seguro = SeguroMoto(cliente, moto, 0, date(2024, 1, 1), date(2024, 12, 31))

    valor = seguro.calcular_valor(800, 0.12)
    assert round(valor, 2) == 976.0

    assert seguro.verificar_vigencia() == False
    print("test_seguro_moto OK")

test_carro()
test_cliente()
test_seguro_carro()
test_seguro_moto()
print("\nTodos os testes passaram!")
