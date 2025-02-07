
"""Construtor para usuario"""
class Usuario:
    def __init__(self, nome, email):
        self.nome = nome
        self.email = email

    """Metodo que gera relatorio"""
    def gerar_relatorio(self):
        print(f"Nome: {self.nome}")
        print(f"Email: {self.email}")
