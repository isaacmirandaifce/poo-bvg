from src.seguro import Seguro
from src.carro import Carro
from src.cliente import Cliente
from datetime import date, timedelta

def test_calcular_valor():
    carro = Carro(2021, "Honda", "Civic", "Branco", "XYZ5678")
    cliente = Cliente("João", "98765432100")
    seguro = Seguro(carro, cliente, 0, "2025-12-31")
    valor = seguro.calcular_valor(1000, 200)
    assert valor == 1200

def test_verificar_vigencia_valido():
    carro = Carro(2021, "Honda", "Civic", "Branco", "XYZ5678")
    cliente = Cliente("João", "98765432100")
    data_futura = (date.today() + timedelta(days=10)).isoformat()
    seguro = Seguro(carro, cliente, 0, data_futura)
    assert seguro.verificar_vigencia() is True

def test_verificar_vigencia_expirado():
    carro = Carro(2021, "Honda", "Civic", "Branco", "XYZ5678")
    cliente = Cliente("João", "98765432100")
    data_passada = (date.today() - timedelta(days=10)).isoformat()
    seguro = Seguro(carro, cliente, 0, data_passada)
    assert seguro.verificar_vigencia() is False
