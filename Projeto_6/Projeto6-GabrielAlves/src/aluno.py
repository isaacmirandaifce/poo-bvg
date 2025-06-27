from typing import List, NamedTuple
from usuario import UsuarioAutenticavel
from interfaces import Relatorio
from enums import TipoUsuario

class Aluno(UsuarioAutenticavel, Relatorio):
    """
    Representa um aluno no sistema, capaz de se autenticar e gerar relatórios.
    """
    TIPO = TipoUsuario.ALUNO

    class HistoricoDisciplinar: # Classe Interna 
        """
        Classe interna que encapsula o histórico de uma disciplina cursada pelo aluno. [cite: 10]
        """
        def __init__(self, nome_disciplina: str, ano_cursado: int, nota: float):
            self.nome_disciplina = nome_disciplina # Nome da disciplina [cite: 10]
            self.ano_cursado = ano_cursado         # Ano cursado [cite: 10]
            self.nota = nota                       # Nota [cite: 10]

        def __str__(self) -> str:
            return f"  - Disciplina: {self.nome_disciplina}, Ano: {self.ano_cursado}, Nota: {self.nota}"

    def __init__(self, nome: str, id_usuario: int, senha: str, curso: str):
        super().__init__(nome, id_usuario, senha)
        self._curso = curso
        self._historico: List[Aluno.HistoricoDisciplinar] = []

    def adicionar_disciplina_cursada(self, nome_disciplina: str, ano_cursado: int, nota: float):
        """Adiciona uma nova disciplina ao histórico do aluno."""
        disciplina = self.HistoricoDisciplinar(nome_disciplina, ano_cursado, nota)
        self._historico.append(disciplina)

    def gerar_relatorio(self) -> None: # Implementação da interface Relatorio [cite: 12]
        """
        Gera um relatório detalhado para o aluno, incluindo seu histórico acadêmico. [cite: 12]
        """
        print("--- Relatório do Aluno ---")
        print(f"Nome: {self.nome}")
        print(f"ID: {self._id_usuario}")
        print(f"Curso: {self._curso}")
        print("Histórico de Disciplinas:")
        if not self._historico:
            print("  Nenhuma disciplina cursada.")
        else:
            for disciplina in self._historico:
                print(disciplina)
        print("-" * 26)