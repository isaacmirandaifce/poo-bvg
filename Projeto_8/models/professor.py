from models.autenticavel import UsuarioAutenticavel

"""Cria construtor de professor"""
class Professor:
    def __init__(self, nome, email, senha, especialidade):
        self.usuario_autenticavel = UsuarioAutenticavel(nome, email, senha)
        self.especialidade = especialidade
        self.disciplinas_ministradas = []  # Lista de disciplinas que o professor ensina

    """Cria o metodo pra adicionar disciplina"""
    def adicionar_disciplina(self, disciplina):
        if disciplina not in self.disciplinas_ministradas:
            self.disciplinas_ministradas.append(disciplina)
