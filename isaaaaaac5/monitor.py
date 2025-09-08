class Usuario:
    def __init__(self, nome="", email="", tipo=""):
        self.nome = nome
        self.email = email
        self.tipo = tipo

class Aluno(Usuario):
    def __init__(self, nome="", email="", matricula="", curso=""):
        super().__init__(nome, email, "Aluno")
        self.matricula = matricula
        self.curso = curso
        self.disciplinas = []
        self.notas = []

class Professor(Usuario):
    def __init__(self, nome="", email="", area=""):
        super().__init__(nome, email, "Professor")
        self.area = area

class Monitor(Aluno, Professor):
    def __init__(self, nome, email, matricula, curso, area):
        # Chamando o construtor de Usuario manualmente para evitar conflitos
        Usuario.__init__(self, nome, email, "Monitor")
        Aluno.__init__(self, nome, email, matricula, curso)
        Professor.__init__(self, nome, email, area)
        self.disciplinas_monitoradas = []

    def adicionar_disciplina_monitorada(self, disciplina):
        self.disciplinas_monitoradas.append(disciplina)

    def gerar_relatorio(self):
        print("Relatório do Monitor:")
        print(f"Nome: {self.nome}")
        print(f"Matrícula: {self.matricula}")
        print(f"Curso: {self.curso}")
        print(f"Área de Atuação: {self.area}")
        print("Disciplinas Monitoradas:")
        for disc in self.disciplinas_monitoradas:
            print(f"- {disc}")

    def listar_disciplinas_monitoradas(self):
        print(f"Disciplinas monitoradas por {self.nome}:")
        for disc in self.disciplinas_monitoradas:
            print(f"- {disc}")
