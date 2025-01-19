from usuario import Usuario

# criação da classe Aluno
class Aluno(Usuario):
    def __init__(self, nome: str, email: str, matricula: str, curso: str):
        super().__init__(nome, email, "Aluno")
        self.matricula = matricula
        self.curso = curso


    def gerar_relatorio(self):
        return f"Aluno: {self.nome}, Matrícula: {self.matricula}, Curso: {self.curso}"