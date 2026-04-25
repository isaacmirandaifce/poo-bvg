#include <iostream>
#include "include/Aluno.h"
#include "include/Professor.h"
#include "include/FuncionarioAdministrativo.h"

int main() {
    Aluno aluno ("Ailton", "1234");

    if (aluno.autenticar("1234")) {
        aluno.adicionarDisciplina("POO", 2026, 9.5);
        aluno.adicionarDisciplina("Estrutura de Dados", 2026, 8.8);
        aluno.gerarRelatorio();
    }
        Professor professor("Carlos", "abcd");
        professor.gerarRelatorio();


        FuncionarioAdministrativo funcionario("Ana", "9999");
        funcionario.gerarRelatorio();

        return 0;
    }

