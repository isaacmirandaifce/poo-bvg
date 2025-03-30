from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio

class Aluno(UsuarioAutenticavel, Relatorio):
    class HistoricoDisciplinar:
        """
        Classe interna para armazenar informações sobre o histórico do aluno.
        """
        def __init__(self, disciplina: str, ano: int, nota: float):
            self.disciplina = disciplina  # Nome da disciplina
            self.ano = ano  # Ano cursado
            self.nota = nota  # Nota obtida

        def detalhes(self) -> str:
            """
            Retorna uma string formatada com os detalhes da disciplina.
            """
            return f"{self.disciplina} (Ano: {self.ano}, Nota: {self.nota})"

    def __init__(self, nome: str, email: str, senha: str):
        super().__init__(nome, email, senha)  # Inicializa o usuário autenticável
        self.historico = []  # Lista para armazenar o histórico do aluno

    def adicionar_disciplina(self, disciplina: str, ano: int, nota: float):
        """
        Adiciona uma disciplina ao histórico do aluno.
        """
        self.historico.append(self.HistoricoDisciplinar(disciplina, ano, nota))

    def gerar_relatorio(self):
        """
        Gera um relatório detalhado com o histórico do aluno.
        """
        print(f"Relatório do Aluno: {self.nome}")
        for disciplina in self.historico:
            print(disciplina.detalhes())
