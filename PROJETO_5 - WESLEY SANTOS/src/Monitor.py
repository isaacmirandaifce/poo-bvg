class Pessoa:
    def __init__(self, nome, email):
        self.nome = nome
        self.email = email

class Aluno(Pessoa):
    def __init__(self, nome, email, matricula, curso):
        super().__init__(nome, email)
        self.matricula = matricula
        self.curso = curso

    def gerar_relatorio(self):
        print(f"Nome: {self.nome}")
        print(f"Email: {self.email}")
        print(f"Matrícula: {self.matricula}")
        print(f"Curso: {self.curso}")

class Professor(Pessoa):
    def __init__(self, nome, email, area_de_atuacao):
        super().__init__(nome, email)
        self.area_de_atuacao = area_de_atuacao

class Monitor(Aluno, Professor):
    def __init__(self, nome, email, matricula, curso, area_de_atuacao):
        Aluno.__init__(self, nome, email, matricula, curso)
        Professor.__init__(self, nome, email, area_de_atuacao)
        self.disciplinas_monitoradas = []

    def adicionar_disciplina_monitorada(self, disciplina):
        self.disciplinas_monitoradas.append(disciplina)

    def gerar_relatorio(self):
        super(Aluno, self).gerar_relatorio()
        print("Disciplinas Monitoradas:")
        for disciplina in self.disciplinas_monitoradas:
            print(f" - {disciplina}")
