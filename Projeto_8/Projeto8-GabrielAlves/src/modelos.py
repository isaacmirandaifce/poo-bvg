# modelos.py

class Aluno:
    def __init__(self, id, nome):
        self.id = id
        self.nome = nome

    def __repr__(self):
        return f"Aluno(ID: {self.id}, Nome: {self.nome})"

class Professor:
    def __init__(self, id, nome):
        self.id = id
        self.nome = nome

    def __repr__(self):
        return f"Professor(ID: {self.id}, Nome: {self.nome})"

class Disciplina:
    def __init__(self, id, nome):
        self.id = id
        self.nome = nome

    def __repr__(self):
        return f"Disciplina(ID: {self.id}, Nome: {self.nome})"