#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include <vector>
#include <string>
#include <cstdio>
int main() {
    Aluno a1("Joao","123","2025","ADS");
    a1.adicionarHistorico("Matematica",2023,9.5);
    a1.adicionarHistorico("Portugues",2023,8.7);
    std::vector<std::string> disciplinas={"Fisica","Quimica"};
    Professor p1("Maria","321","Fisica",disciplinas);
    FuncionarioAdministrativo f1("Carlos","abc","Secretaria","Auxiliar");
    a1.gerarRelatorio();
    p1.gerarRelatorio();
    f1.gerarRelatorio();
    return 0;
}
