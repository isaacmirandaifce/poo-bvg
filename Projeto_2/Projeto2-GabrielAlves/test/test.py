import sys
import os
sys.path.append(os.path.abspath('../src'))

import unittest
from cliente import Cliente
from modelo import Modelo
from carro import Carro
from seguro import Seguro
from seguro_veiculo import SeguroCarro, SeguroMoto
from datetime import datetime

class TestSeguro(unittest.TestCase):
    
    def setUp(self):
        # Criar objetos usados nos testes
        self.cliente = Cliente("João Silva", "123.456.789-00")
        self.modelo = Modelo("Corolla")
        self.carro = Carro(2020, "Toyota", self.modelo, "Branco", "XYZ-1234")
        self.seguro = Seguro(self.carro, self.cliente, 0, "2024-01-01 a 2025-01-01")
        self.seguro_carro = SeguroCarro(self.cliente, 1500, "2024-01-01 a 2025-01-01", self.carro)
        self.seguro_moto = SeguroMoto(self.cliente, 1200, "2024-01-01 a 2025-01-01", 300)

    def test_cliente_cpf_encapsulado(self):
        self.assertEqual(self.cliente.get_cpf(), "123.456.789-00")
    
    def test_carro_placa_encapsulada(self):
        self.assertEqual(self.carro.get_placa(), "XYZ-1234")

    def test_alterar_cor(self):
        self.carro.alterar_cor("Vermelho")
        self.assertEqual(self.carro.cor, "Vermelho")

    def test_definir_valor_seguro(self):
        valor = self.seguro.definir_valor(1000, 0.15)
        self.assertAlmostEqual(valor, 1150.0)

    def test_seguro_esta_vigente(self):
        self.assertTrue(self.seguro.esta_vigente())

    def test_calcular_valor_seguro_carro(self):
        valor = self.seguro_carro.calcular_valor()
        esperado = 1500 * 1.20  # 20% taxa
        self.assertAlmostEqual(valor, esperado)

    def test_calcular_valor_seguro_moto(self):
        valor = self.seguro_moto.calcular_valor()
        esperado = 1200 * 1.15  # 15% taxa para 300 cilindradas
        self.assertAlmostEqual(valor, esperado)

if __name__ == "__main__":
    unittest.main()
