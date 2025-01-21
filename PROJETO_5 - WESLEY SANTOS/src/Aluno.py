from Usuario import Usuario

class Aluno(Usuario):
    def __init__(self, nome="", email="", matricula="", curso=""):
        super().__init__(nome, email, "Aluno")
        self.matricula = matricula
        self.curso = curso
        self.disciplinas_cursadas = []

    def gerar_relatorio(self):
        print(f"Nome: {self.nome}\nMatrícula: {self.matricula}\nCurso: {self.curso}")

    def exibir_informacoes(self, com_notas=False):
        self.gerar_relatorio()
        if com_notas:
            print("Disciplinas Cursadas:")
            for disciplina in self.disciplinas_cursadas:
                print(f" - {disciplina}")

    def adicionar_disciplina(self, disciplina):
        self.disciplinas_cursadas.append(disciplina)
