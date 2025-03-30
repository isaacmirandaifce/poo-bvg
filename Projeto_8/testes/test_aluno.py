import unittest
from src.models.Aluno import Aluno
from src.models.TipoUsuario import TipoUsuario


class TestAluno(unittest.TestCase):
    
    def setUp(self):
        # Configurações iniciais para os testes
        self.aluno = Aluno(
            nome="João Silva",
            email="joao.silva@email.com",
            tipo=TipoUsuario.ALUNO,
            matricula="12345",
            curso="Ciência da Computação",
            disciplinas="Matemática, Programação",
            senha="senha123"
        )

    def test_gerarRelatorio(self):
        # Teste para verificar a geração do relatório
        relatorio_esperado = (
            "Nome: João Silva\n"
            "Matricula: 12345\n"
            "Curso: Ciência da Computação\n"
            "Disciplinas: Matemática, Programação"
        )
        self.assertEqual(self.aluno.gerarRelatorio(), relatorio_esperado)

    def test_autenticar_com_senha_correta(self):
        # Teste para verificar a autenticação com a senha correta
        self.assertTrue(self.aluno.autenticar("senha123"))

    def test_autenticar_com_senha_incorreta(self):
        # Teste para verificar a autenticação com a senha incorreta
        self.assertFalse(self.aluno.autenticar("senhaErrada"))

    def test_historico_disciplinar(self):
        # Teste para verificar a classe interna HistoricoDisciplinar
        historico = self.aluno.HistoricoDisciplinar("Matemática", 2023, 9.5)
        self.assertEqual(historico.nome_disciplina, "Matemática")
        self.assertEqual(historico.ano_cursado, 2023)
        self.assertEqual(historico.nota, 9.5)

    def test_aluno_sem_senha(self):
        # Teste para verificar a autenticação sem senha definida
        aluno_sem_senha = Aluno(
            nome="Maria Oliveira",
            email="maria.oliveira@email.com",
            tipo=TipoUsuario.ALUNO,
            matricula="67890",
            curso="Engenharia Elétrica",
            disciplinas="Física, Cálculo",
            senha=""
        )
        self.assertFalse(aluno_sem_senha.autenticar("qualquer_senha"))

if __name__ == "__main__":
    unittest.main()
