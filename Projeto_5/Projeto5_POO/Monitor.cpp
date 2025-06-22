#include "Monitor.h"
#include <iostream>
using namespace std;

Monitor::Monitor(string n, string e, string m, string c, string area)
    : Usuario(n, e, "Monitor"), Aluno(n, e, m, c), Professor(n, e, area) {}

void Monitor::adicionarDisciplinaMonitorada(string d) {
    disciplinasMonitoradas.push_back(d);
}

void Monitor::gerarRelatorio() const {
    cout << "Monitor: " << nome << " | Matrícula: " << matricula
         << " | Curso: " << curso << " | Área de atuação: " << areaDeAtuacao << endl;
    cout << "Disciplinas Monitoradas:\n";
    for (const auto& d : disciplinasMonitoradas) {
        cout << " - " << d << endl;
    }
}
