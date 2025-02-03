from aluno import Aluno
from professor import Professor
from funcionario_administrativo import FuncionarioAdministrativo

def main():
    # Criando um aluno
    aluno = Aluno("João Silva", "joao@email.com", "senha123")
    aluno.adicionar_disciplina("Matemática", 2022, 9.5)
    aluno.adicionar_disciplina("Física", 2023, 8.0)
    aluno.gerar_relatorio()

    # Autenticando aluno
    if aluno.autenticar("senha123"):
        print("Autenticação do Aluno bem-sucedida!")
    else:
        print("Autenticação do Aluno falhou!")

    # Criando um professor
    professor = Professor("Maria Souza", "maria@email.com", "senha456", "Física")
    professor.adicionar_disciplina("Física I")
    professor.adicionar_disciplina("Física II")
    professor.gerar_relatorio()

    # Criando um funcionário administrativo
    funcionario = FuncionarioAdministrativo("Carlos Lima", "carlos@email.com", "senha789", 
                                             "Recursos Humanos", "Analista")
    funcionario.gerar_relatorio()

if __name__ == "__main__":
    main()
