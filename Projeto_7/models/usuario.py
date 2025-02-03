class Usuario:
    
    #Inicia o construtor de usuario
    def __init__(self, nome, email):
        self.nome = nome
        self.email = email

    #Metodo para gerar relatorio
    def gerar_relatorio(self):
        print(f"Nome: {self.nome}")
        print(f"Email: {self.email}")
