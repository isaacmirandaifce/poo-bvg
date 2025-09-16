#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"
#include <iostream>

int main() {
    Aluno aluno("Lucas", "lucas@email.com", "Engenharia", 12345);
    Professor professor("Maria", "maria@email.com", "Matemática", "Doutora");
    FuncionarioAdministrativo funcionario("Carlos", "carlos@email.com", "Financeiro", "Gerente");
    Monitor monitor("Ana", "ana@email.com", "Engenharia", 54321, "Física", "Mestre");

    aluno.gerarRelatorio();
    cout << "--------------------------" << endl;
    professor.gerarRelatorio();
    cout << "--------------------------" << endl;
    funcionario.gerarRelatorio();
    cout << "--------------------------" << endl;
    monitor.gerarRelatorio();

    return 0;
}
