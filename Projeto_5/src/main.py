from Aluno import Aluno
from Professor import Professor
from FuncionarioAdm import FuncionarioAdm
from Monitor import Monitor

def main():
    # Criando um aluno
    aluno = Aluno("João", "joao@email.com", "20230001", "Engenharia")
    aluno.adicionar_disciplina("Cálculo")
    aluno.adicionar_disciplina("Física")

    # Criando um professor
    professor = Professor("Maria", "maria@email.com", "Matemática Aplicada")
    professor.adicionar_disciplina("Cálculo")
    professor.adicionar_disciplina("Álgebra Linear")

    # Criando um funcionário administrativo
    funcionario = FuncionarioAdm("Carlos", "carlos@email.com", "RH", "Analista de Pessoal")

    # Criando um monitor
    monitor = Monitor("Ana", "ana@email.com", "20230002", "Engenharia", "Matemática")
    monitor.adicionar_disciplina_monitorada("Cálculo")
    monitor.adicionar_disciplina_monitorada("Física")

    # Gerando relatórios
    print("\n--- Relatórios ---")
    aluno.gerar_relatorio()
    professor.gerar_relatorio()
    funcionario.gerar_relatorio()
    monitor.gerar_relatorio()

if __name__ == "__main__":
    main()
