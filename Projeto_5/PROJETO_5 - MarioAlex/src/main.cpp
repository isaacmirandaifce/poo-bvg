#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    std::vector<Usuario*> usuarios;

    Aluno* a = new Aluno("Maru", "maru@email.com", "20251234", "ADS");
    a->adicionarDisciplina("POO");
    a->adicionarDisciplina("Banco de Dados");

    Professor* p = new Professor("Prof. Ana", "ana@faculdade.edu", "Sistemas");
    p->adicionarDisciplina("Estrutura de Dados");

    FuncionarioAdministrativo* f = new FuncionarioAdministrativo("João RH", "joao@faculdade.edu", "RH", "Coordenador");

    Monitor* m = new Monitor("Carlos", "carlos@faculdade.edu", "20258888", "ADS", "Sistemas");
    m->adicionarDisciplinaMonitorada("Algoritmos");

    usuarios.push_back(a);
    usuarios.push_back(p);
    usuarios.push_back(f);
    usuarios.push_back(m);

    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
        std::cout << "--------------------\n";
    }

    // Liberando memória
    for (Usuario* u : usuarios) {
        delete u;
    }

    return 0;
}
