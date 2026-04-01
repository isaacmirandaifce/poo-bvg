#include "Monitor.h"
#include <iostream>

using namespace std;

Monitor::Monitor(string nome, string email, string matricula, string curso, string area)
 :Aluno(nome, email, matricula, curso),
  Professor(nome, email, area) {}

void Monitor::listarMonitorias() const {
    cout << "Disciplinas monitoradas:" << endl;
    for (const auto& d : disciplinasMonitoradas) {
        cout << "- " << d << endl;
    }
}