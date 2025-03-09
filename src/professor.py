class Professor:
    def __init__(self, nome: str, disciplina: str):
        self.nome = nome
        self.disciplina = disciplina

    def __str__(self):
        return f"Professor: {self.nome}, Disciplina: {self.disciplina}"