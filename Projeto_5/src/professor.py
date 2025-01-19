from usuario import Usuario

class Professor(Usuario):
    def __init__(self, nome, email, area_de_atuacao, disciplinas_ministradas):
        super().__init__(nome, email, "Professor")
        self.area_de_atuacao = area_de_atuacao
        self.disciplinas_ministradas = disciplinas_ministradas

    def gerar_relatorio(self):
        return (f"Professor: {self.nome}\n"
                f"Área de Atuação: {self.area_de_atuacao}\n"
                f"Disciplinas Ministradas: {', '.join(self.disciplinas_ministradas) or 'Nenhuma'}")
