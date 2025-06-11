#include "Monitor.h"
#include <iostream>

Monitor::Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string area)
    : Usuario(nome, email, "Monitor"), Aluno(nome, email, matricula, curso), Professor(nome, email, area) {}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas Monitoradas: ";
    for (const auto& d : disciplinasMonitoradas)
        std::cout << d << " ";
    std::cout << "\n";
}

void Monitor::gerarRelatorio() const {
    Aluno::gerarRelatorio();
    std::cout << "Área de atuação (como monitor): " << Professor::areaDeAtuacao << "\n";
    listarDisciplinasMonitoradas();
}
