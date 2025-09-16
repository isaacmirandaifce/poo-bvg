import unittest
from aluno import Aluno
from filtro import Filtro

class TestFiltro(unittest.TestCase):
    def test_filtrar_por_condicao(self):
        aluno1 = Aluno("Kaique", 1, "Engenharia", [7.5, 8.0, 6.5])
        aluno2 = Aluno("Maria", 2, "Medicina", [9.0, 8.5, 7.5])
        filtro = Filtro[Aluno]()
        filtro.adicionar_elemento(aluno1)
        filtro.adicionar_elemento(aluno2)

        alunos_filtrados = filtro.filtrar_por_condicao(lambda aluno: aluno.media() > 7.0)

        self.assertEqual(len(alunos_filtrados), 2)
        self.assertEqual(alunos_filtrados[0].nome, "Kaique")
        self.assertEqual(alunos_filtrados[1].nome, "Maria")

    def test_imprimir_todos(self):
        aluno1 = Aluno("Kaique", 1, "Engenharia", [7.5, 8.0, 6.5])
        filtro = Filtro[Aluno]()
        filtro.adicionar_elemento(aluno1)

        def acao(aluno):
            self.assertEqual(aluno.nome, "Kaique")
        
        filtro.imprimir_todos(acao)

if __name__ == "__main__":
    unittest.main()
