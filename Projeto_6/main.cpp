#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

int main() {
    Aluno aluno;
    aluno.adicionarHistorico("Matemática", 2022, 9.5);
    aluno.adicionarHistorico("Física", 2022, 8.0);

    if (aluno.autenticar("senha123")) {
        aluno.gerarRelatorio();
    }

    Professor professor;
    if (professor.autenticar("senha321")) {
        professor.gerarRelatorio();
    }

    FuncionarioAdministrativo funcionario;
    if (funcionario.autenticar("senha456")) {
        funcionario.gerarRelatorio();
    }

    return 0;
}
