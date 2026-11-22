"""Testes automatizados das regras de cálculo de prêmio.

Cobrem os casos de fronteira de cada regra herdada do código legado,
a validação do tipo de imóvel, a abstração de Seguro, a associação
entre Cliente e seus seguros e o encapsulamento do CPF.

Execução (dentro da pasta da entrega):
    python -m unittest discover -s tests -v
"""

import sys
import unittest
from pathlib import Path

# Permite importar o pacote models, que fica dentro de src/.
sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "src"))

from models.cliente import Cliente  # noqa: E402
from models.seguros import (  # noqa: E402
    Seguro,
    SeguroAuto,
    SeguroResidencial,
    SeguroVida,
)


class TestSeguroAuto(unittest.TestCase):
    """Regra: ano < 2010 paga base x 1.2; os demais, base x 1.05."""

    def setUp(self):
        self.cliente = Cliente("Teste", "12345678901")

    def criar(self, ano):
        return SeguroAuto(self.cliente, 1000, modelo="Teste", ano=ano, placa="AAA0A00")

    def test_ano_2009_paga_fator_antigo(self):
        self.assertAlmostEqual(self.criar(2009).calcular_premio(), 1200.00)

    def test_ano_2010_paga_fator_novo(self):
        self.assertAlmostEqual(self.criar(2010).calcular_premio(), 1050.00)

    def test_hilux_2026(self):
        self.assertAlmostEqual(self.criar(2026).calcular_premio(), 1050.00)


class TestSeguroVida(unittest.TestCase):
    """Regra: idade > 60 paga base x 2.0; os demais, base x 1.1."""

    def setUp(self):
        self.cliente = Cliente("Teste", "12345678901")

    def test_idade_60_nao_dobra(self):
        seguro = SeguroVida(self.cliente, 1000, idade=60)
        self.assertAlmostEqual(seguro.calcular_premio(), 1100.00)

    def test_idade_61_dobra(self):
        seguro = SeguroVida(self.cliente, 1000, idade=61)
        self.assertAlmostEqual(seguro.calcular_premio(), 2000.00)


class TestSeguroResidencial(unittest.TestCase):
    """Regra: casa paga base x 1.15; apartamento, base x 1.05."""

    def setUp(self):
        self.cliente = Cliente("Teste", "12345678901")

    def test_casa(self):
        seguro = SeguroResidencial(self.cliente, 1000, tipo_imovel="CASA")
        self.assertAlmostEqual(seguro.calcular_premio(), 1150.00)

    def test_apartamento(self):
        seguro = SeguroResidencial(self.cliente, 1000, tipo_imovel="APARTAMENTO")
        self.assertAlmostEqual(seguro.calcular_premio(), 1050.00)

    def test_aceita_minusculas_e_espacos(self):
        seguro = SeguroResidencial(self.cliente, 1000, tipo_imovel=" casa ")
        self.assertAlmostEqual(seguro.calcular_premio(), 1150.00)

    def test_tipo_invalido_gera_erro(self):
        with self.assertRaises(ValueError):
            SeguroResidencial(self.cliente, 1000, tipo_imovel="CHACARA")

    def test_tipo_invalido_nao_fica_associado_ao_cliente(self):
        with self.assertRaises(ValueError):
            SeguroResidencial(self.cliente, 1000, tipo_imovel="CHACARA")
        self.assertEqual(len(self.cliente.seguros), 0)


class TestConceitosPOO(unittest.TestCase):
    """Abstração, polimorfismo, associação e encapsulamento."""

    def setUp(self):
        self.cliente = Cliente("Teste", "12345678901")

    def test_seguro_nao_pode_ser_instanciado(self):
        with self.assertRaises(TypeError):
            Seguro(self.cliente, 1000)

    def test_polimorfismo_sem_verificar_tipo(self):
        seguros = [
            SeguroAuto(self.cliente, 1000, modelo="X", ano=2008, placa="AAA0A00"),
            SeguroVida(self.cliente, 1000, idade=65),
            SeguroResidencial(self.cliente, 1000, tipo_imovel="CASA"),
        ]
        premios = [s.calcular_premio() for s in seguros]
        for obtido, esperado in zip(premios, [1200.00, 2000.00, 1150.00]):
            self.assertAlmostEqual(obtido, esperado)

    def test_cliente_registra_seus_seguros(self):
        SeguroVida(self.cliente, 1000, idade=30)
        SeguroResidencial(self.cliente, 1000, tipo_imovel="APARTAMENTO")
        self.assertEqual(len(self.cliente.seguros), 2)

    def test_cpf_exibido_mascarado(self):
        self.assertEqual(self.cliente.cpf, "***.***.***-01")


if __name__ == "__main__":
    unittest.main()