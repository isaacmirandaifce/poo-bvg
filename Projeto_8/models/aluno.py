from models.autenticavel import UsuarioAutenticavel
from models.disciplina import Disciplina

class Aluno:
    """Classe que representa um aluno no sistema acadêmico"""

    def __init__(self, UsuarioAutenticavel, matricula, curso):
        """
        Inicializa um objeto Aluno.

        :param UsuarioAutenticavel: Objeto UsuarioAutenticavel associado ao aluno
        :param matricula: Número de matrícula do aluno
        :param curso: Nome do curso que o aluno está matriculado
        """
        self.UsuarioAutenticavel = UsuarioAutenticavel  # Autenticação do aluno
        self.matricula = matricula  # Matrícula do aluno
        self.curso = curso  # Curso do aluno
        self.historico = []  # Histórico de disciplinas

    def adicionar_disciplina(self, disciplina):
        """Adiciona uma disciplina ao histórico do aluno."""
        self.historico.append(disciplina)

    def listar_disciplinas(self):
        """Retorna a lista de disciplinas cursadas pelo aluno."""
        return self.historico

    def to_dict(self):
        """Converte o objeto Aluno para um dicionário serializável"""
        return {
            "nome": self.UsuarioAutenticavel.nome,
            "email": self.UsuarioAutenticavel.email,
            "matricula": self.matricula,
            "curso": self.curso,
            "historico": [{"nome": disciplina.nome, "carga_horaria": disciplina.carga_horaria, "nota": disciplina.get_nota()} for disciplina in self.historico]
        }

    @staticmethod
    def from_dict(dados):
        """Cria um objeto Aluno a partir de um dicionário"""
        usuario = UsuarioAutenticavel(dados["nome"], dados["email"], None)  # Senha não é carregada
        aluno = Aluno(usuario, dados["matricula"], dados["curso"])
        aluno.historico = [Disciplina(d["nome"], d["carga_horaria"]) for d in dados["historico"]]
        for d, disciplina in zip(dados["historico"], aluno.historico):
            disciplina.set_nota(d["nota"])
        return aluno
