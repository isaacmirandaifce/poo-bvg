//Código de Alissa Garcia ADS S3

#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"
using namespace std;

int main() {
 Aluno a("Alissa", "alissa@email.com", "Aluno", "202401", "ADS");
    a.adicionarNota(8.5);
    a.adicionarNota(9.0);
    a.adicionarNota(10);

    Professor p("Isaac", "isaac@email.com", "Professor", "Desenvolvimento");
    p.disciplinasAdicionadas("POO");

    Funcionario_adm f("Marcos", "marcos@email.com", "Funcionario", "Secretaria", "Atendente");

    cout << "\n--- Relatório aluno sem notas ---\n";
    a.gerarRelatorio();

    cout << "\n--- Relatório aluno com notas ---\n";
    a.gerarRelatorio(true);

    cout << "\n--- Polimorfismo ---\n";
    vector<Usuario*> usuarios;
    usuarios.push_back(&a);
    usuarios.push_back(&p);
    usuarios.push_back(&f);

    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
        cout << "-----------------\n";
    }

    cout << "\n--- Monitoria ---\n";
    Monitor m("Alissa", "alissa@email.com", "Monitor", "202401", "ADS", "Programação Estruturada");
    m.adicionarDisciplinaMonitorada("POO");
    m.gerarRelatorio();



    return 0;
}