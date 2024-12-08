import unittest
import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')
from Carro import Carro
from Cliente import Cliente
from Seguro import Seguro

class TestCarro(unittest.TestCase):
    def setUp(self):
        """Configura os dados para os testes."""
        self.carro = Carro(2022, "Toyota", "Corolla", "Preto", "XYZ-1234")

    def test_exibir_detalhes(self):
        """Testa o método exibir_detalhes de Carro."""
        detalhes = self.carro.exibir_detalhes()
        self.assertEqual(detalhes["ano"], 2022)
        self.assertEqual(detalhes["marca"], "Toyota")
        self.assertEqual(detalhes["modelo"], "Corolla")
        self.assertEqual(detalhes["cor"], "Preto")
        self.assertEqual(detalhes["placa"], "XYZ-1234")


class TestCliente(unittest.TestCase):
    def setUp(self):
        """Configura os dados para os testes."""
        self.cliente = Cliente("João", "123.456.789-00")

    def test_exibir_detalhes(self):
        """Testa o método exibir_detalhes de Cliente."""
        detalhes = self.cliente.exibir_detalhes()
        self.assertEqual(detalhes["nome"], "João")
        self.assertEqual(detalhes["cpf"], "123.456.789-00")


class TestSeguro(unittest.TestCase):
    def setUp(self):
        self.cliente = Cliente("João", "123.456.789-00")
        self.carro = Carro(2022, "Toyota", "Corolla", "Preto", "XYZ-1234")
        self.seguro = Seguro(self.carro, self.cliente, 1500.0, "31-12-2024")

    def test_calcular_valor(self):
        valor_final = self.seguro.calcular_valor(1500.0, 0.1)
        self.assertEqual(valor_final, 1650.0)

    def test_verificar_vigencia_ativa(self):
        vigencia_ativa = self.seguro.verificar_vigencia()
        self.assertTrue(vigencia_ativa)

    def test_verificar_vigencia_expirada(self):
        seguro_expirado = Seguro(self.carro, self.cliente, 1500.0, "01-01-2020")
        vigencia_expirada = seguro_expirado.verificar_vigencia()
        self.assertFalse(vigencia_expirada)

    def test_exibir_detalhes(self):
        """Testa o método exibir_detalhes de Seguro."""
        detalhes = self.seguro.exibir_detalhes()
        self.assertEqual(detalhes["cliente"]["nome"], "João")
        self.assertEqual(detalhes["carro"]["marca"], "Toyota")
        self.assertEqual(detalhes["valor_seguro"], 1500.0)
        self.assertEqual(detalhes["vigencia"], "31-12-2024")


if __name__ == '__main__':
    unittest.main()
