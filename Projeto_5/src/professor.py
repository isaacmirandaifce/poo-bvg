from usuario import Usuario

# criação da classe Professor
class  Professor(Usuario):
    def __init__(self, nome: str, email: str, area_de_atuacao: str, disciplinas: list):
        super().__init__(nome, email, "Professor")
        self.area_de_atuacao = area_de_atuacao
        self.disciplinas = disciplinas

    def gerar_relatorio(self):
        return f"Professor: {self.nome}, Área de Atuação: {self.area_de_atuacao}, Disciplinas: {', '.join(self.disciplinas)}"