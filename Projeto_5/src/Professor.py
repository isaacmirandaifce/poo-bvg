from Usuario import Usuario

class Professor(Usuario):
    def __init__(self, nome, email, area_de_atuacao):
        super().__init__(nome, email, "Professor")
        self.area_de_atuacao = area_de_atuacao
        self.disciplinas_ministradas = []

    def adicionar_disciplina(self, disciplina):
        self.disciplinas_ministradas.append(disciplina)

    def gerar_relatorio(self):
        relatorio = f"Professor: {self.nome}\nÁrea de Atuação: {self.area_de_atuacao}\nDisciplinas Ministradas: {', '.join(self.disciplinas_ministradas)}"
        print(relatorio)
