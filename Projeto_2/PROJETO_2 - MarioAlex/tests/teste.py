import unittest
from datetime import date
from src.carro import Carro
from src.cliente import Cliente
from src.seguro import SeguroCarro

class TestSeguroCarro(unittest.TestCase):
    def setUp(self):
        self.cliente = Cliente("Maria Oliveira", "987.654.321-00")
        self.carro = Carro(2019, "Honda", "Civic", "Preto", "ABC-9876")
        self.seguro = SeguroCarro(
            cliente=self.cliente,
            carros=[self.carro],
            valor=0,
            vigencia_inicio=date(2024, 1, 1),
            vigencia_fim=date(2025, 1, 1)
        )

    def test_valor_seguro(self):
        valor = self.seguro.calcular_valor(2000, 1.1)
        self.assertEqual(valor, 2200.0)

    def test_vigencia_valida(self):
        self.assertTrue(self.seguro.verificar_vigencia())

    def test_exibir_cliente(self):
        self.assertIn("Maria Oliveira", self.cliente.exibir_informacoes())

    def test_exibir_detalhes_carro(self):
        detalhes = self.carro.exibir_detalhes()
        self.assertIn("Honda", detalhes)
        self.assertIn("Civic", detalhes)

if __name__ == '__main__':
    unittest.main()