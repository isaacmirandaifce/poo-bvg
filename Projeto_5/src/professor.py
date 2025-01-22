from usuario import Usuario

class Professor(Usuario):
    def __init__(self, nome, email, area_de_atuacao, disciplinas_ministradas=None, tipo="Professor"):
        # Inicializa atributos da classe base e específicos de Professor
        super().__init__(nome, email, tipo)  
        self.area_de_atuacao = area_de_atuacao
        self.disciplinas_ministradas = disciplinas_ministradas if disciplinas_ministradas else []

    def gerar_relatorio(self):
        # Gera um relatório com informações do professor
        print(f"Professor: {self.nome}")
        print(f"Área de Atuação: {self.area_de_atuacao}")
        print("Disciplinas Ministradas: ", ", ".join(self.disciplinas_ministradas))
