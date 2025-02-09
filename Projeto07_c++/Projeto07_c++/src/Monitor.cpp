#include "../include/Monitor.h"
#include <iostream>
using namespace std;

Monitor::Monitor(const string& nome, const string& email, const string& matricula, const string& curso,
                 const string& areaDeAtuacao, const vector<string>& disciplinasMinistradas, const vector<string>& disciplinasMonitoradas)
    : Aluno(nome, email, matricula, curso, ""), Professor(nome, email, areaDeAtuacao, ""), disciplinasMonitoradas(disciplinasMonitoradas) {
    for (const auto& disciplina : disciplinasMinistradas) {
        adicionarDisciplina(disciplina);
    }
}

void Monitor::gerarRelatorio() const {
    Aluno::gerarRelatorio();
    cout << "Disciplinas Ministradas: ";
    for (const auto& disciplina : getDisciplinasMinistradas()) {
        cout << disciplina << " ";
    }
    cout << endl;
    cout << "Disciplinas Monitoradas: ";
    for (const auto& disciplina : disciplinasMonitoradas) {
        cout << disciplina << " ";
    }
    cout << endl;
}