from Aluno import Aluno
from Professor import Professor

class Monitor(Aluno, Professor):
    def __init__(self, nome, email, matricula, curso, area_de_atuacao):
        Aluno.__init__(self, nome, email, matricula, curso)
        Professor.__init__(self, nome, email, area_de_atuacao)
        self.disciplinas_monitoradas = []

    def adicionar_disciplina_monitorada(self, disciplina):
        self.disciplinas_monitoradas.append(disciplina)

    def gerar_relatorio(self):
        relatorio = f"Monitor: {self.nome}\nCurso: {self.curso}\nDisciplinas Monitoradas: {', '.join(self.disciplinas_monitoradas)}"
        print(relatorio)