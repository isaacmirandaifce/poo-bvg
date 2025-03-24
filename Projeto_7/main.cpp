#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Filtro.h"

int main() {
    Aluno a("Joao", "joao@email.com", "123", "2022001", "Computacao");
    Professor p("Carlos", "carlos@email.com", "Matematica");
    p.adicionarDisciplina("Calculo");
    FuncionarioAdministrativo f("Ana", "ana@email.com", "RH", "Gerente");
    
    a.gerarRelatorio();
    p.gerarRelatorio();
    f.gerarRelatorio();
    
    return 0;
}