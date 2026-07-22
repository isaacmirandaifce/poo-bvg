#include <iostream>
#include "Monitor.h"

using namespace std;

Monitor::Monitor() : Usuario(), Aluno(), Professor() {}

Monitor::Monitor(string nome, string email, string matricula, string curso, string areaDeAtuacao)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, areaDeAtuacao) {}

void Monitor::adicionarDisciplinaMonitorada(const string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::listarDisciplinasMonitoradas() const {
    cout << "Disciplinas monitoradas: ";
    if (disciplinasMonitoradas.empty()) {
        cout << "nenhuma";
    }
    for (size_t i = 0; i < disciplinasMonitoradas.size(); ++i) {
        cout << disciplinasMonitoradas[i];
        if (i != disciplinasMonitoradas.size() - 1) cout << ", ";
    }
    cout << endl;
}

void Monitor::gerarRelatorio() const {
    cout << "[Relatorio de Monitor]" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << " | Curso: " << curso << endl;
    cout << "Area de atuacao (como professor): " << areaDeAtuacao << endl;
    listarDisciplinasMonitoradas();
}
