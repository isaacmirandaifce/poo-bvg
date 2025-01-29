from Usuario import Usuario

class Aluno(Usuario):
    def __init__(self, nome, email, matricula, curso):
        super().__init__(nome, email, "Aluno")
        self.matricula = matricula
        self.curso = curso
        self.disciplinas = []

    def adicionar_disciplina(self, disciplina):
        self.disciplinas.append(disciplina)

    def gerar_relatorio(self):
        relatorio = f"Aluno: {self.nome}\nMatrícula: {self.matricula}\nCurso: {self.curso}\nDisciplinas: {', '.join(self.disciplinas)}"
        print(relatorio)

    def gerar_relatorio_completo(self, notas):
        relatorio = f"Aluno: {self.nome}\nMatrícula: {self.matricula}\nCurso: {self.curso}\n"
        for disciplina, nota in notas.items():
            relatorio += f"{disciplina}: {nota}\n"
        print(relatorio)
