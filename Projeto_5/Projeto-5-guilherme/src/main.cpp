#include <iostream>
#include <vector>
#include "aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    std::vector<Usuario*> usuarios;

    Aluno* a = new Aluno("Guilherme-Alves", "guilherme.12@gmail.com", "2023123", "ADS");
    a->adicionarDisciplina(Disciplina("POO", 60, 7));
    a->adicionarDisciplina(Disciplina("IHC", 40, 7));

    Professor* p = new Professor("João", "joao@uni.com", "Engenharia de Software");
    p->adicionarDisciplina("POO");
    p->adicionarDisciplina("Estrutura de Dados");

    FuncionarioAdministrativo* f = new FuncionarioAdministrativo("Maria", "maria@uni.com", "Secretaria", "Assistente");

    Monitor* m = new Monitor("Carlos", "carlos@uni.com", "2023555", "ADS", "Programação");
    m->adicionarDisciplinaMonitorada("POO");

    usuarios.push_back(a);
    usuarios.push_back(p);
    usuarios.push_back(f);
    usuarios.push_back(m);

    for (Usuario* u : usuarios) {
        std::cout << "\n------------------------\n";
        u->gerarRelatorio();
    }

    // Limpeza
    for (Usuario* u : usuarios) {
        delete u;
    }

    return 0;
}
