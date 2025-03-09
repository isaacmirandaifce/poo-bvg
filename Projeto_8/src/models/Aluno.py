from src.models.Usuario import Usuario
from src.models.Relatorio import Relatorio
from src.models.TipoUsuario import TipoUsuario
from src.models.UsuarioAutenticavel import UsuarioAutenticavel


class Aluno(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome='indefinido', email='indefinido', tipo=TipoUsuario.ALUNO, matricula='indefinida', curso='indefinido', disciplinas=None, senha='indefinida'):
        super().__init__(nome, email, tipo, senha)
        # Atributos específicos da classe Aluno
        self._matricula = matricula
        self._curso = curso
        self._disciplinas = disciplinas if disciplinas is not None else []
        self._historico = []

    def gerarRelatorio(self) -> str:
        """
        Implementa o método da interface Relatorio.
        """
        return (
            f"Nome: {self._nome}\n"
            f"Matricula: {self._matricula}\n"
            f"Curso: {self._curso}\n"
            f"Disciplinas: {', '.join(self._disciplinas)}"
        )

    def autenticar(self, senha: str) -> bool:
        """
        Implementa o método abstrato da classe UsuarioAutenticavel.
        Verifica se a senha fornecida está correta.
        """
        return self._senha == senha

    def adicionar_disciplina(self, disciplina):
        """ Adiciona uma disciplina à lista do aluno. """
        self._disciplinas.append(disciplina)

    def adicionar_historico(self, nome_disciplina, ano_cursado, nota):
        """ Adiciona um registro ao histórico disciplinar do aluno. """
        self._historico.append(self.HistoricoDisciplinar(nome_disciplina, ano_cursado, nota))

    def to_dict(self):
        """ Converte o objeto para um dicionário para facilitar a serialização. """
        return {
            "nome": self._nome,
            "email": self._email,
            "tipo": self._tipo.value,
            "matricula": self._matricula,
            "curso": self._curso,
            "disciplinas": self._disciplinas,
            "historico": [h.to_dict() for h in self._historico]
        }

    @classmethod
    def from_dict(cls, data):
        """ Cria um objeto Aluno a partir de um dicionário. """
        aluno = cls(
            nome=data["nome"],
            email=data["email"],
            tipo=TipoUsuario(data["tipo"]),
            matricula=data["matricula"],
            curso=data["curso"],
            disciplinas=data.get("disciplinas", []),
            senha="indefinida"  # Senha não deve ser recuperada diretamente
        )
        for h in data.get("historico", []):
            aluno.adicionar_historico(h["nome_disciplina"], h["ano_cursado"], h["nota"])
        return aluno

    class HistoricoDisciplinar:
        def __init__(self, nome_disciplina, ano_cursado, nota):
            """
            Classe interna que armazena informações sobre o histórico disciplinar do aluno.
            """
            self.nome_disciplina = nome_disciplina
            self.ano_cursado = ano_cursado
            self.nota = nota

        def to_dict(self):
            """ Converte o histórico disciplinar para um dicionário. """
            return {
                "nome_disciplina": self.nome_disciplina,
                "ano_cursado": self.ano_cursado,
                "nota": self.nota
            }
