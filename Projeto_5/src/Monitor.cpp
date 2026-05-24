#include "Monitor.h"

Monitor::Monitor(string nome,
                 string email,
                 string matricula,
                 string curso,
                 string areaDeAtuacao)

    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, areaDeAtuacao) {
}

void Monitor::adicionarMonitoria(string disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::listarMonitorias() {

    cout << "\n===== DISCIPLINAS MONITORADAS ====="
         << endl;

    for (string d : disciplinasMonitoradas) {
        cout << "- " << d << endl;
    }
}

void Monitor::gerarRelatorio() {

    cout << "\n===== RELATORIO DO MONITOR ====="
         << endl;

    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Curso: " << curso << endl;
    cout << "Area de Atuacao: "
         << areaDeAtuacao << endl;

    listarMonitorias();
}

Monitor::~Monitor() {
}