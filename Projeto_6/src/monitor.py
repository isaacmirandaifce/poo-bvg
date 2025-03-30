from aluno import Aluno
from professor import Professor

class Monitor(Aluno, Professor):
    def __init__(self, nome, email, matricula, curso, area_de_atuacao, disciplinas_ministradas=None):
        # Inicializa atributos de Aluno e Professor
        Aluno.__init__(self, nome, email, matricula, curso)
        Professor.__init__(self, nome, email, area_de_atuacao, disciplinas_ministradas)

    def listar_disciplinas_monitoradas(self):
        # Lista as disciplinas monitoradas pelo monitor
        print(f"Monitor: {self.nome}")
        print(f"Disciplinas Monitoradas: ", ", ".join(self.disciplinas_ministradas))
