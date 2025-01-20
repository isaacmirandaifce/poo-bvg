#include "../include/Monitor.h"

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& matricula,
                 const std::string& curso, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Monitor"), Aluno(nome, email, matricula, curso), Professor(nome, email, areaDeAtuacao) {}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::gerarRelatorio() const {
    Aluno::gerarRelatorio();
    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& disciplina : disciplinasMonitoradas) {
        std::cout << "- " << disciplina << "\n";
    }
}
