#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Aluno
    Aluno aluno("Gabyss", "gabyss@email.com", "202301", "Engenharia");
    vector<float> notas = {8.5, 9.0, 7.5};
    aluno.gerarRelatorio();          // Sobrescrita
    aluno.gerarRelatorio(notas);     // Sobrecarga

    // Professor
    Professor professor("Mandysan", "mandysan_@email.com", "Computação", {"POO", "Estruturas de Dados"});
    professor.gerarRelatorio();      // Sobrescrita

    // Funcionário Administrativo
    FuncionarioAdministrativo funcionario("Pedrow", "pedrow@email.com", "Financeiro", "Gerente");
    funcionario.gerarRelatorio();    // Sobrescrita

    // Monitor
    Monitor monitor("karolis", "karolis@email.com", "202302", "Matemática", "Exatas", 
                    {"Cálculo"}, {"Cálculo I", "Cálculo II"});
    monitor.gerarRelatorio();        // Sobrescrita

    return 0;
}
