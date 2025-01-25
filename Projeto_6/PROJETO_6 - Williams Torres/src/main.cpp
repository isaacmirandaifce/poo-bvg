#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

int main() {
    Aluno aluno("João", "12345");
    aluno.adicionarDisciplina("Matemática", 2023, 8.5);
    aluno.adicionarDisciplina("Física", 2024, 9.0);

    Professor professor("Maria", "67890", "Física");
    FuncionarioAdministrativo funcionario("Carlos", "54321", "RH");

    std::cout << "Autenticando João...\n";
    if (aluno.autenticar("12345")) {
        std::cout << "Autenticação bem-sucedida!\n";
        std::cout << "Relatório do aluno:\n" << aluno.gerarRelatorio();
    } else {
        std::cout << "Senha incorreta.\n";
    }

    std::cout << "\nRelatório do professor:\n" << professor.gerarRelatorio();
    std::cout << "\nRelatório do funcionário administrativo:\n" << funcionario.gerarRelatorio();

    return 0;
}