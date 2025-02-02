from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio

class Professor(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome: str, email: str, senha: str, area_de_atuacao: str):
        super().__init__(nome, email, senha)  # Inicializa o usuário autenticável
        self.area_de_atuacao = area_de_atuacao  # Define a área de atuação do professor
        self.disciplinas_ministradas = []  # Lista de disciplinas ministradas pelo professor

    def adicionar_disciplina(self, disciplina: str):
        """
        Adiciona uma disciplina à lista de disciplinas ministradas.
        """
        self.disciplinas_ministradas.append(disciplina)

    def gerar_relatorio(self):
        """
        Gera um relatório com as disciplinas ministradas e a área de atuação.
        """
        print(f"Relatório do Professor: {self.nome}")
        print(f"Área de Atuação: {self.area_de_atuacao}")
        print("Disciplinas Ministradas: ", ", ".join(self.disciplinas_ministradas))
