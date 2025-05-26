import unittest
from datetime import datetime, timedelta
from src.cliente import Cliente
from src.modelo import Modelo
from src.carro import Carro
from src.moto import Moto
from src.seguro.seguro_carro import SeguroCarro
from src.seguro.seguro_moto import SeguroMoto

class TestSeguroVeiculo(unittest.TestCase):
    def setUp(self):
        self.modelo = Modelo("Civic")
        self.cliente = Cliente("João", "123.456.789-00")
        self.carro = Carro(2020, "Honda", self.modelo, "Preto", "ABC-1234")
        self.moto = Moto("Yamaha", "MT-03", 2021, "XYZ-9876")

    def test_cliente(self):
        self.assertEqual(self.cliente.nome, "João")
        self.assertEqual(self.cliente.get_cpf(), "123.456.789-00")

    def test_modelo(self):
        self.assertEqual(self.modelo.nome, "Civic")

    def test_carro(self):
        self.assertEqual(self.carro.get_placa(), "ABC-1234")
        self.carro.atualizar_cor("Azul")
        self.assertEqual(self.carro.cor, "Azul")

    def test_moto(self):
        self.assertEqual(self.moto.get_placa(), "XYZ-9876")

    def test_seguro_carro_calculo(self):
        vigencia = f"01/01/2024 a {(datetime.today() + timedelta(days=30)).strftime('%d/%m/%Y')}"
        seguro = SeguroCarro(self.cliente, [self.carro], 1000.0, vigencia)
        valor = seguro.calcular_valor()
        self.assertAlmostEqual(valor, 1050.0)

    def test_seguro_moto_calculo(self):
        vigencia = f"01/01/2024 a {(datetime.today() + timedelta(days=30)).strftime('%d/%m/%Y')}"
        seguro = SeguroMoto(self.cliente, self.moto, 1000.0, vigencia)
        valor = seguro.calcular_valor()
        self.assertAlmostEqual(valor, 1070.0)

    def test_vigencia_valida(self):
        vigencia = f"01/01/2024 a {(datetime.today() + timedelta(days=1)).strftime('%d/%m/%Y')}"
        seguro = SeguroCarro(self.cliente, [self.carro], 1000.0, vigencia)
        self.assertTrue(seguro.verificar_vigencia())

    def test_vigencia_invalida(self):
        vigencia = "01/01/2024 a 01/01/2020"
        seguro = SeguroMoto(self.cliente, self.moto, 1000.0, vigencia)
        self.assertFalse(seguro.verificar_vigencia())

if __name__ == '__main__':
    unittest.main()
