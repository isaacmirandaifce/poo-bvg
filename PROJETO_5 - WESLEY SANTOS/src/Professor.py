class Usuario:
    def __init__(self, nome='', email='', tipo=''):
        self.nome = nome
        self.email = email
        self.tipo = tipo


class Professor(Usuario):
    def __init__(self, nome='', email='', area_de_atuacao=''):
        super().__init__(nome, email, tipo='Professor')
        self.area_de_atuacao = area_de_atuacao
        self.disciplinas_ministradas = []

    def gerar_relatorio(self):
        print(f"Nome: {self.nome}")
        print(f"Área de Atuação: {self.area_de_atuacao}")

    def adicionar_disciplina(self, disciplina):
        self.disciplinas_ministradas.append(disciplina)
