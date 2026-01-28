#include "Monitor.h"

// Construtor padrão
Monitor::Monitor() : Usuario(), Aluno(), Professor() {}

// Construtor parametrizado
Monitor::Monitor(string nome, string email, string tipo,
                 string matricula, string curso,
                 string areaDeAtuacao)
: Usuario(nome, email, tipo),
  Aluno(nome, email, tipo, matricula, curso),
  Professor(nome, email, tipo, areaDeAtuacao) {
}

// Adiciona disciplina monitorada
void Monitor::adicionarDisciplinaMonitorada(string disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

// Lista disciplinas monitoradas
void Monitor::listarDisciplinasMonitoradas() {
    cout << "Disciplinas monitoradas:" << endl;
    for (string d : disciplinasMonitoradas) {
        cout << "- " << d << endl;
    }
}

// Relatório completo
void Monitor::gerarRelatorio() {
    Aluno::gerarRelatorio();
    listarDisciplinasMonitoradas();
}
