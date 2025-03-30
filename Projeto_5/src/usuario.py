class Usuario:
    def __init__(self, nome, email, tipo="Aluno"):
        # Inicializa atributos comuns a todos os usuários
        self.nome = nome
        self.email = email
        self.tipo = tipo

    def gerar_relatorio(self):
        # Gera um relatório básico com as informações do usuário
        print(f"Nome: {self.nome}")
        print(f"Email: {self.email}")
        print(f"Tipo: {self.tipo}")
