from aluno import Aluno
from professor import Professor

# criação da classe Monitor
class Monitor(Aluno, Professor):
    def __init__(self, nome: str, email: str, matricula: str, curso: str, area_de_atuacao: str, disciplinas_monitoradas: list):
        Aluno.__init__(self, nome, email, matricula, curso)
        Professor.__init__(self, nome, email, area_de_atuacao, disciplinas_monitoradas)
        self.disciplinas_monitoradas = disciplinas_monitoradas


    def listar_disciplinas_monitoradas(self):
        return f"Monitor {self.nome} monitora as disciplinas: {', '.join(self.disciplinas_monitoradas)}"