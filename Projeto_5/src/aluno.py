from usuario import Usuario  # Importa a classe base Usuario

class Aluno(Usuario):  
    def __init__(self, nome, email, matricula, curso, tipo="Aluno"):  
        # Inicializa Aluno com atributos específicos e chama o construtor da classe base
        super().__init__(nome, email, tipo)
        self.matricula = matricula
        self.curso = curso

    def gerar_relatorio(self):  
        # Gera um relatório básico do aluno
        print(f"Aluno: {self.nome}")
        print(f"Matrícula: {self.matricula}")
        print(f"Curso: {self.curso}")

    def gerar_relatorio_detalhado(self, notas=None):  
        # Gera um relatório detalhado, incluindo notas, se fornecidas
        self.gerar_relatorio()
        if notas:
            print(f"Notas: {notas}")
        else:
            print("Notas não informadas.")
