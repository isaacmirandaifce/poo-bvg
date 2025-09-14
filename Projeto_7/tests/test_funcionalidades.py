# tests/test_funcionalidades.py
import unittest
from src.aluno import Aluno
from src.filtro import Filtro

class TestFuncionalidades(unittest.TestCase):
    def setUp(self):
        self.aluno1 = Aluno(nome="Carlos Silva", id_usuario=101, senha="123", curso="ADS")
        self.aluno1.adicionar_disciplina_historico("POO", 2024, 10.0)
        self.aluno1.adicionar_disciplina_historico("Banco de Dados", 2024, 8.0)

        self.aluno2 = Aluno(nome="Ana Pereira", id_usuario=102, senha="456", curso="CC")
        self.aluno2.adicionar_disciplina_historico("Cálculo I", 2023, 5.0)

    def test_calcular_media_aluno(self):
        self.assertAlmostEqual(self.aluno1.calcular_media(), 9.0)
        self.assertAlmostEqual(self.aluno2.calcular_media(), 5.0)

    def test_filtro_por_condicao(self):
        filtro_alunos = Filtro()
        filtro_alunos.adicionar_elemento(self.aluno1)
        filtro_alunos.adicionar_elemento(self.aluno2)

        # Filtra alunos com média maior que 7.0
        resultado = filtro_alunos.filtrar_por_condicao(lambda a: a.calcular_media() > 7.0)
        
        self.assertEqual(len(resultado), 1)
        self.assertEqual(resultado[0].nome, "Carlos Silva")

if __name__ == '__main__':
    unittest.main()