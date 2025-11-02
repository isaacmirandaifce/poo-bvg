from datetime import date, timedelta
from src.modelo import Modelo
from src.carro import Carro
from src.cliente import Cliente
from src.seguro import SeguroCarro

def teste_exemplo_seguro():
    modelo = Modelo("Corolla")
    carro = Carro(2020, "Toyota", modelo, "Branco", "XYZ-1234")
    cliente = Cliente("João Silva", "12345678900")
    inicio = date.today() - timedelta(days=10)
    fim = date.today() + timedelta(days=355)
    seguro = SeguroCarro(carro, cliente, 1500.0, inicio, fim, franquia=100.0)

    assert seguro.verificar_vigencia() is True
    valor = seguro.calcular_valor(1500.0, 0.10)
    assert isinstance(valor, float)

# Esse teste é simples e serve para mostrar funcionamento; se quiser, eu adapto para pytest com asserts mais detalhados.