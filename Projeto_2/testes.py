"""
Módulo de testes automatizados para validação de fronteiras e regras de negócio.
"""
import unittest
from src.models.cliente import Cliente
from src.models.seguros import SeguroAuto, SeguroVida, SeguroResidencial

class TestSeguros(unittest.TestCase):
    
    def setUp(self):
        """Cria um cliente padrão para ser usado em todos os testes."""
        self.cliente = Cliente("Teste", "111.222.333-44")

    def test_fronteira_ano_carro(self):
        """Testa o comportamento no limite do ano 2010."""
        seguro_2009 = SeguroAuto(self.cliente, 1000.0, "XYZ-0000", 2009)
        self.assertEqual(seguro_2009.calcular_premio(), 1200.0)
        
        seguro_2010 = SeguroAuto(self.cliente, 1000.0, "XYZ-0000", 2010)
        self.assertEqual(seguro_2010.calcular_premio(), 1050.0)

    def test_fronteira_idade_vida(self):
        """Testa o comportamento no limite da idade 60."""
        seguro_60 = SeguroVida(self.cliente, 1000.0, 60)
        self.assertEqual(seguro_60.calcular_premio(), 1100.0)
    
        seguro_61 = SeguroVida(self.cliente, 1000.0, 61)
        self.assertEqual(seguro_61.calcular_premio(), 2000.0)

    def test_validacao_tipo_imovel(self):
        """Testa se o sistema bloqueia tipos de imóveis não autorizados."""
        with self.assertRaises(ValueError):
            SeguroResidencial(self.cliente, 1000.0, "FAZENDA")
            
    def test_validacao_valor_base(self):
        """Testa se o sistema bloqueia valores negativos de prêmio."""
        with self.assertRaises(ValueError):
            SeguroVida(self.cliente, -500.0, 30)

if __name__ == '__main__':
    unittest.main()