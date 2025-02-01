from src.models.Usuario import Usuario
from src.models.Relatorio import Relatorio
from src.models.TipoUsuario import TipoUsuario
from src.models.UsuarioAutenticavel import UsuarioAutenticavel


class Aluno(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome='indefinido', email='indefinido', tipo=TipoUsuario.ALUNO, matricula='indefinida', curso='indefinido', disciplinas='indefinido', senha='indefinida'):
        
        super().__init__(nome, email, tipo, senha)
        # Atributos específicos da classe Aluno
        self._matricula = matricula
        self._curso = curso
        self._disciplinas = disciplinas

    def gerarRelatorio(self) -> str:
        """
        Implementa o método da interface Relatorio.
        """
        return (
            f"Nome: {self._nome}\n"
            f"Matricula: {self._matricula}\n"
            f"Curso: {self._curso}\n"
            f"Disciplinas: {self._disciplinas}"
        )

    def autenticar(self, senha: str) -> bool:
        """
        Implementa o método abstrato da classe UsuarioAutenticavel.
        Verifica se a senha fornecida está correta.
        """
        return self._senha == senha

    class HistoricoDisciplinar:
        def __init__(self, nome_disciplina, ano_cursado, nota):
            """
            Classe interna que armazena informações sobre o histórico disciplinar do aluno.
            """
            self.nome_disciplina = nome_disciplina
            self.ano_cursado = ano_cursado
            self.nota = nota
