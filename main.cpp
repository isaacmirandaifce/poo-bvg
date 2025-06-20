#include <iostream>
#include <vector>
#include "aluno.h"
#include "professor.h"
#include "funcionarioadministrativo.h"
#include "monitor.h"

int main() {
    std::vector<usuario*> usuarios;

    aluno* a = new aluno("Joao", "joao@email.com", "2023001", "ADS");
    a->adicionarDisciplina("Logica de Programacao");
    usuarios.push_back(a);

    professor* p = new professor("Maria", "maria@email.com", "Computacao");
    p->adicionarDisciplina("POO");
    usuarios.push_back(p);

    funcionarioadministrativo* f = new funcionarioadministrativo("Carlos", "carlos@email.com", "RH", "Analista");
    usuarios.push_back(f);

    monitor* m = new monitor("Ana", "ana@email.com", "2023002", "ADS", "Matematica");
    m->adicionarDisciplina("Calculo");
    m->adicionarDisciplinaMonitorada("Calculo I");
    usuarios.push_back(m);

    for (usuario* u : usuarios) {
        std::cout << "====================\n";
        u->gerarRelatorio();
    }

    for (usuario* u : usuarios) delete u;

    return 0;
}

