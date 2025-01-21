from Aluno import Aluno
from Professor import Professor
from FuncionarioAdministrativo import FuncionarioAdministrativo
from Monitor import Monitor

def main():
    # Lista para armazenar os objetos de usuários
    usuarios = []

    # Criação de objetos
    aluno = Aluno(nome="João", email="joao@example.com", matricula="20230101", curso="Ciência da Computação")
    aluno.adicionar_disciplina("Programação 1")

    professor = Professor(nome="Dr. Silva", email="silva@example.com", area_de_atuacao="Inteligência Artificial")
    professor.adicionar_disciplina("Machine Learning")

    funcionario = FuncionarioAdministrativo(nome="Ana", email="ana@example.com", departamento="Financeiro", cargo="Assistente Administrativa")

    monitor = Monitor(nome="Carlos", email="carlos@example.com", matricula="20230102", curso="Matemática", area_de_atuacao="Cálculo")
    monitor.adicionar_disciplina_monitorada("Álgebra Linear")

    # Adicionando os objetos à lista de usuários
    usuarios.append(aluno)
    usuarios.append(professor)
    usuarios.append(funcionario)
    usuarios.append(monitor)

    # Gerando relatórios de forma polimórfica
    for usuario in usuarios:
        usuario.gerar_relatorio()
        print("\n")

