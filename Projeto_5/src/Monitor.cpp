#include "Monitor.h"
#include <iostream>
using namespace std;

Monitor::Monitor(const string& nome, const string& email, const string& matricula, const string& curso,
                 const string& areaDeAtuacao, const vector<string>& disciplinasMinistradas, const vector<string>& disciplinasMonitoradas)
    : Aluno(nome, email, matricula, curso), Professor(nome, email, areaDeAtuacao, disciplinasMinistradas),
      disciplinasMonitoradas(disciplinasMonitoradas) {}

void Monitor::gerarRelatorio() const {
    Aluno::gerarRelatorio();
    cout << "Disciplinas Monitoradas: ";
    for (const string& disciplina : disciplinasMonitoradas) {
        cout << disciplina << " ";
    }
    cout << endl;
}
