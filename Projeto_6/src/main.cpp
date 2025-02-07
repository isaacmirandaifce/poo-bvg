#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

int main() {
    Aluno aluno("João", "senha123");
    aluno.adicionarDisciplina("Matemática", 2023, 8.5);
    aluno.adicionarDisciplina("Física", 2023, 7.0);
    aluno.gerarRelatorio();

    Professor professor("Maria", "senha456");
    professor.gerarRelatorio();

    FuncionarioAdministrativo funcionario("Carlos", "senha789");
    funcionario.gerarRelatorio();

    return 0;
}