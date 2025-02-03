# models/professor.py
class Professor:
    def __init__(self, nome, email, senha, especialidade):
        from models.autenticavel import UsuarioAutenticavel
        
        self.usuario_autenticavel = UsuarioAutenticavel(nome, email, senha)
        self.especialidade = especialidade
        self.disciplinas_ministradas = []  # Lista de disciplinas que o professor ensina

    def adicionar_disciplina(self, disciplina):
        """ Adiciona uma disciplina ao professor. """
        if disciplina not in self.disciplinas_ministradas:
            self.disciplinas_ministradas.append(disciplina)
