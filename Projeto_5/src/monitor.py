from aluno import Aluno
from professor import Professor

class Monitor(Aluno, Professor):
    def __init__(self, nome, email, matricula, curso, area_de_atuacao, disciplinas_ministradas):
        Aluno.__init__(self, nome, email, matricula, curso)
        Professor.__init__(self, area_de_atuacao, disciplinas_ministradas)

    def disciplinas_monitoradas(self):
        return self.disciplinas_ministradas

    def gerar_relatorio(self):
        # Combina relatórios de Aluno e Professor
        relatorio_aluno = Aluno.gerar_relatorio(self)
        relatorio_professor = Professor.gerar_relatorio(self)
        return f"{relatorio_aluno}\n{relatorio_professor}"
