#include "Monitor.h"
#include <iostream>

Monitor::Monitor() : Aluno(), Professor() {}

Monitor::Monitor(const std::string& nome, const std::string& matricula, const std::string& curso, const std::string& email, 
                 const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinas, 
                 const std::vector<std::string>& disciplinasMonitoradas)
    : Aluno(nome, matricula, curso, email), Professor(nome, email, areaDeAtuacao, disciplinas), disciplinasMonitoradas(disciplinasMonitoradas) {}

void Monitor::gerarRelatorio() const {
    std::cout << "Relatório do Monitor:\n";
    Aluno::exibirInformacoes();
    std::cout << "Disciplinas Monitoradas:\n";
    listarDisciplinasMonitoradas();
}

void Monitor::listarDisciplinasMonitoradas() const {
    for (const auto& disciplina : disciplinasMonitoradas) {
        std::cout << " - " << disciplina << "\n";
    }
}
