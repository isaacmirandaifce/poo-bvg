#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"
int main() {
    Aluno a("Joao", "joao@email.com", "Aluno", "123", "ADS");
    Professor p("Maria", "maria@email.com", "Professor", "Matematica");
    FuncionarioAdministrativo f("Carlos", "carlos@email.com", "Funcionario", "Financeiro", "Analista");
    a.gerarRelatorio();
    p.gerarRelatorio();
    f.gerarRelatorio();
    return 0;
}
