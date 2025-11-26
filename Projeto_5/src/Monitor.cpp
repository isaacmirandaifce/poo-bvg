#include "Monitor.h"

Monitor::Monitor() : Aluno(), Professor() { tipo = "Monitor"; }

Monitor::Monitor(const string &nome, const string &email, const string &matricula, const string &curso, const string &area)
    : Aluno(nome, email, matricula, curso), Professor(nome, email, area) { tipo = "Monitor"; }

Monitor::~Monitor() {}

void Monitor::adicionarDisciplinaMonitorada(const string &disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::listarDisciplinasMonitoradas() const {
    cout << "Disciplinas monitoradas: ";
    for (const auto &d : disciplinasMonitoradas) cout << d << " ; ";
    cout << endl;
}

void Monitor::gerarRelatorio() const {
    cout << "---- Relatorio Monitor (combinado) ----" << endl;
    // usar dados de Aluno (primeiro base Aluno)
    Aluno::gerarRelatorio();
    cout << "Area (como Professor): " << Professor::getArea() << endl;
    listarDisciplinasMonitoradas();
}