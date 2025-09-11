# tests/test_autenticacao.py
import unittest
from src.aluno import Aluno
from src.professor import Professor

class TestAutenticacao(unittest.TestCase):
    def setUp(self):
        self.aluno = Aluno(nome="Carlos Silva", id_usuario=101, senha="senha123", curso="ADS")
        self.professor = Professor(nome="Dra. Ana Costa", id_usuario=201, senha="prof_abc", departamento="CC")

    def test_autenticacao_aluno_sucesso(self):
        self.assertTrue(self.aluno.autenticar("senha123"))

    def test_autenticacao_aluno_falha(self):
        self.assertFalse(self.aluno.autenticar("senha_errada"))

    def test_autenticacao_professor_sucesso(self):
        self.assertTrue(self.professor.autenticar("prof_abc"))

    def test_autenticacao_professor_falha(self):
        self.assertFalse(self.professor.autenticar("prof_xyz"))

if __name__ == '__main__':
    unittest.main()