class Aluno:
    def __init__(self, nome: str, media: float, disciplinas: List[str]):
        self.nome = nome
        self.media = media
        self.disciplinas = disciplinas

    def __str__(self):
        return f"Aluno: {self.nome}, Média: {self.media}, Disciplinas: {', '.join(self.disciplinas)}"