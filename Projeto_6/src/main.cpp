#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

int main() {
    Aluno aluno("Fernanda", "202401", "1234");
    aluno.adicionarDisciplina("POO", 2024, 9.5);
    aluno.adicionarDisciplina("Estruturas de Dados", 2024, 8.7);

    if (aluno.autenticar("1234")) {
        aluno.gerarRelatorio();
    }

    Professor prof("Carlos", "P001", "abcd");
    prof.gerarRelatorio();

    FuncionarioAdministrativo func("Ana", "F001", "admin");
    func.gerarRelatorio();

    return 0;
}
