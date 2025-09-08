class Usuario:
    def __init__(self, nome="", email="", tipo=""):
        self.nome = nome
        self.email = email
        self.tipo = tipo
class Professor(Usuario):
    def __init__(self, nome="", email="", area_de_atuacao=""):
        super().__init__(nome, email, "Professor")
        self.area = area_de_atuacao
        self.disciplinas_ministradas = []

    def adicionar_disciplina(self, disciplina):
        self.disciplinas_ministradas.append(disciplina)

    def gerar_relatorio(self):
        print("Relatório do Professor:")
        print(f"Nome: {self.nome}")
        print(f"Área de Atuação: {self.area}")
        print("Disciplinas ministradas:")
        for disc in self.disciplinas_ministradas:
            print(f"- {disc}")
