#include "Monitor.h"
#include <iostream>

Monitor::Monitor(std::string nome, std::string email,
                 std::string matricula, std::string curso,
                 std::string area)
    : Usuario(nome, email, "Monitor"), Aluno(nome, email, matricula, curso),
      Professor(nome, email, area) {}

void Monitor::adicionarDisciplinaMonitorada(std::string nomeDisciplina) {
    disciplinasMonitoradas.push_back(nomeDisciplina);
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& d : disciplinasMonitoradas) {
        std::cout << "- " << d << "\n";
    }
}

void Monitor::gerarRelatorio() const {
    std::cout << "=== Relatório do Monitor ===\n";
    Aluno::gerarRelatorio();
    listarDisciplinasMonitoradas();
}
