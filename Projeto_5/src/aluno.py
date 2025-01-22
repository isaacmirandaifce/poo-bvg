from usuario import Usuario

class Aluno(Usuario):
    def __init__(self, nome, email, matricula, curso):
        super().__init__(nome, email, "Aluno")
        self.matricula = matricula
        self.curso = curso
        self.disciplinas_cursadas = []

    def adicionar_disciplina(self, disciplina):
        self.disciplinas_cursadas.append(disciplina)

    def gerar_relatorio(self):
        return (f"Aluno: {self.nome}\n"
                f"Matrícula: {self.matricula}\n"
                f"Curso: {self.curso}\n"
                f"Disciplinas Cursadas: {', '.join(self.disciplinas_cursadas) or 'Nenhuma'}")

    def exibir_detalhes(self, incluir_notas=False):
        relatorio = self.gerar_relatorio()
        if incluir_notas:
            # Simulação de notas (adapte conforme necessário)
            notas = {disciplina: "Aprovado" for disciplina in self.disciplinas_cursadas}
            notas_str = "\n".join(f"{disc}: {nota}" for disc, nota in notas.items())
            relatorio += f"\nNotas:\n{notas_str}"
        return relatorio
