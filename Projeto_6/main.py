from aluno import Aluno
from professor import Professor
from funcionario_administrativo import FuncionarioAdministrativo

def main():
    a1 = Aluno("Maria", "maria123", "senha123")
    a1.adicionar_disciplina("POO", 2023, 9.5)
    a1.adicionar_disciplina("ED", 2023, 8.7)

    p1 = Professor("Carlos", "carlosprof", "12345", "Algoritmos")

    f1 = FuncionarioAdministrativo("Ana", "anaadm", "senhaadm", "Secretaria")

    usuarios = [a1, p1, f1]

    for user in usuarios:
        senha = input(f"Digite a senha de {user.nome}: ")
        if user.autenticar(senha):
            user.gerar_relatorio()
        else:
            print("Senha incorreta!")

        print("-" * 40)

if __name__ == "__main__":
    main()
