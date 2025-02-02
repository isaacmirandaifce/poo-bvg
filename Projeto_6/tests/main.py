from aluno import Aluno
from professor import Professor
from funcionario_administrativo import FuncionarioAdministrativo
from tipo_usuario import TipoUsuario

def main():
    # Criando instâncias
    aluno = Aluno("Maria Fernanda", "mariaf@email.com", "senha123")
    aluno._historico.adicionar_disciplina("POO", 2024, 8.5)
    aluno._historico.adicionar_disciplina("Direito Digital", 2025, 8.7)

    professor = Professor("João Isaac", "joaoisaac@email.com", "senha456")
    funcionario = FuncionarioAdministrativo("Stênio", "stenio@example.com", "senha789")

    # Autenticação
    print(f"Aluno autenticado: {aluno.autenticar('senha123')}")
    print(f"Professor autenticado: {professor.autenticar('senha456')}")
    print(f"Funcionário autenticado: {funcionario.autenticar('senha789')}")

    # Gerando relatórios
    print(aluno.gerar_relatorio())
    print(professor.gerar_relatorio())
    print(funcionario.gerar_relatorio())

if __name__ == "__main__":
    main()