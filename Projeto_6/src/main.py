from aluno import Aluno
from professor import Professor
from funcionario_administrativo import FuncionarioAdministrativo

def main():
    aluno = Aluno('Matheus', '12345')
    aluno.historico.adicionar_disciplina('Matemática', 2024, 9.5)
    aluno.historico.adicionar_disciplina('Física', 2024, 8.0)

    professor = Professor('Dr. Silva', '67890')
    funcionario = FuncionarioAdministrativo('Maria', '11223')

    print(aluno.gerar_relatorio())
    print(professor.gerar_relatorio())
    print(funcionario.gerar_relatorio())

    # Teste de autenticação
    print(aluno.autenticar('12345'))  # True
    print(professor.autenticar('wrongpass'))  # False

if __name__ == "__main__":
    main()
