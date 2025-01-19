from aluno import Aluno
from professor import Professor
from funcionario_administrativo import FuncionarioAdministrativo
from monitor import Monitor 

def main():
    usuarios = [
        Aluno("Maria Fernanda", "mariaf@email.com", "34567", "ADS"),
        Professor("João Isaac", "joaoisaac@email.com", "Engenharia", ["POO", "Banco de Dados"]),
        FuncionarioAdministrativo("Jocélio Alves", "jocelioa@email.com", "ADM", "Administrador"),
        Monitor("José Igor", "joseigor@email.com", "88322", "ADS", "Programação", ["Python", "C++", "Java"])
    ]

    for usuario in usuarios:
        print(usuario.gerarRelatorio())

if __name__ == "__main__":
    main()