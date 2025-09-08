class Usuario:
    def __init__(self, nome="", email="", tipo=""):
        self.nome = nome
        self.email = email
        self.tipo = tipo

    def exibir_informacoes(self):
        print(f"Usuário: {self.nome} | Email: {self.email} | Tipo: {self.tipo}")


class Aluno(Usuario):
    def __init__(self, nome="", email="", matricula="", curso=""):
        super().__init__(nome, email, "Aluno")
        self.matricula = matricula
        self.curso = curso
        self.disciplinas = []
        self.notas = []

    def adicionar_disciplina(self, disciplina, nota):
        self.disciplinas.append(disciplina)
        self.notas.append(nota)

    def gerar_relatorio(self):
        print("Relatório do Aluno:")
        print(f"Nome: {self.nome}")
        print(f"Matrícula: {self.matricula}")
        print(f"Curso: {self.curso}")
        print("Disciplinas cursadas:")
        for disciplina, nota in zip(self.disciplinas, self.notas):
            print(f"- {disciplina} (Nota: {nota})")

    def exibir_informacoes(self, mostrar_notas=False):
        print(f"Aluno: {self.nome} | Matrícula: {self.matricula} | Curso: {self.curso}")
        if mostrar_notas:
            print("Notas:")
            for disciplina, nota in zip(self.disciplinas, self.notas):
                print(f"- {disciplina}: {nota}")
