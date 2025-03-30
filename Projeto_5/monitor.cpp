#include "Monitor.h"
#include <iostream>

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& areaDeAtuacao)
    : Aluno(nome, email, matricula, curso), Professor(nome, email, areaDeAtuacao) {}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::gerarRelatorio() const {
    Aluno::gerarRelatorio();
    std::cout << "Disciplinas Monitoradas: ";
    for (const auto& disc : disciplinasMonitoradas)
        std::cout << disc << " ";
    std::cout << "\n";
}
