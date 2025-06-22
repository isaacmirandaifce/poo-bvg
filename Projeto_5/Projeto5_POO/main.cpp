#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"
#include "Disciplina.h"

using namespace std;

int main() {
    Aluno a1("Maria", "maria@email.com", "2023A", "ADS");
    Disciplina d1("POO", 60);
    d1.setNota(8.5);
    Disciplina d2("Estrutura de Dados", 80);
    d2.setNota(6.0);
    a1.adicionarDisciplina(d1);
    a1.adicionarDisciplina(d2);

    Professor p1("Carlos", "carlos@faculdade.com", "Engenharia de Software");
    p1.adicionarDisciplina("Algoritmos");
    p1.adicionarDisciplina("Banco de Dados");

    FuncionarioAdministrativo f1("João", "joao@adm.com", "Financeiro", "Analista");

    Monitor m1("Lucas", "lucas@aluno.com", "2023B", "SI", "Banco de Dados");
    m1.adicionarDisciplinaMonitorada("Banco de Dados");
    m1.adicionarDisciplinaMonitorada("Algoritmos");

    vector<Usuario*> usuarios;
    usuarios.push_back(&a1);
    usuarios.push_back(&p1);
    usuarios.push_back(&f1);
    usuarios.push_back(&m1);

    for (Usuario* u : usuarios) {
        cout << "\n--- Relatório ---\n";
        u->gerarRelatorio();
    }

    return 0;
}
