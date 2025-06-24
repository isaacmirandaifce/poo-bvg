#include "Monitor.h"

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& matricula,
                 const std::string& curso, const std::string& area)
    : Usuario(nome, email, "Monitor"), Aluno(nome, email, matricula, curso), Professor(nome, email, area) {}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::gerarRelatorio() const {
    Aluno::gerarRelatorio();
    std::cout << "[Monitor] Disciplinas monitoradas: ";
    for (const auto& d : disciplinasMonitoradas)
        std::cout << d << ", ";
    std::cout << "\n";
}