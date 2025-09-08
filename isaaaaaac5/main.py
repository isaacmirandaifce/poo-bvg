from FuncionáriosAdministrativo import FuncionarioAdministrativo
from aluno import Aluno
from monitor import Monitor
from professor import Professor


def main():
    # Criação dos objetos
    aluno = Aluno("Maria", "maria@email.com", "2021001", "Engenharia")
    aluno.adicionar_disciplina("Matemática", 8.5)
    aluno.adicionar_disciplina("Física", 7.0)

    professor = Professor("João", "joao@email.com", "Exatas")
    professor.adicionar_disciplina("Matemática")
    professor.adicionar_disciplina("Cálculo")

    funcionario = FuncionarioAdministrativo("Ana", "ana@email.com", "Secretaria", "Assistente")

    monitor = Monitor("Carlos", "carlos@email.com", "2021002", "Computação", "Exatas")
    monitor.adicionar_disciplina_monitorada("Algoritmos")
    monitor.adicionar_disciplina_monitorada("Estruturas de Dados")

    # Lista de objetos do tipo Usuario (polimorfismo)
    usuarios = [aluno, professor, funcionario, monitor]

    # Chamada polimórfica
    for usuario in usuarios:
        usuario.gerar_relatorio()
        print("-" * 30)

    # Teste de sobrecarga em Aluno (em Python via argumento opcional)
    print("Exibindo informações do aluno (sem notas):")
    aluno.exibir_informacoes()

    print("\nExibindo informações do aluno (com notas):")
    aluno.exibir_informacoes(mostrar_notas=True)

    # Teste de método adicional em Monitor
    print("\nListando disciplinas monitoradas:")
    monitor.listar_disciplinas_monitoradas()


if __name__ == "__main__":
    main()
