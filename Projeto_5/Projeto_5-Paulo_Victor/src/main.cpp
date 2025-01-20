#include <iostream>
#include <vector>
#include "../include/Aluno.h"
#include "../include/Professor.h"
#include "../include/FuncionarioAdministrativo.h"
#include "../include/Monitor.h"

int main() {
    Aluno aluno("Joao Silva", "joao@email.com", "A001", "Engenharia");
    aluno.adicionarDisciplina("Matematica");
    aluno.adicionarDisciplina("Fisica");

    Professor professor("Dr. Ana", "ana@email.com", "Ciencias Exatas");
    professor.adicionarDisciplina("Algebra Linear");
    professor.adicionarDisciplina("Calculo");

    FuncionarioAdministrativo funcionario("Carlos Souza", "carlos@email.com", "Administracao", "Secretario");

    Monitor monitor("Mariana Costa", "mariana@email.com", "A002", "Engenharia", "Ciencias");
    monitor.adicionarDisciplinaMonitorada("Fisica Aplicada");

    std::vector<Usuario*> usuarios = {&aluno, &professor, &funcionario, &monitor};

    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio();
        std::cout << "-------------------\n";
    }

    return 0;
}
