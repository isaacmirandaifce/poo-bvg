#include "Monitor.h"
#include <iostream>

Monitor::Monitor() : Aluno() {}

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& senha,
                 const std::string& matricula, const std::string& curso,
                 const std::vector<std::string>& disciplinasMonitoradas)
    : Aluno(nome, email, senha, matricula, curso), disciplinasMonitoradas(disciplinasMonitoradas) {}

bool Monitor::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void Monitor::exibirInformacoes() const {
    Aluno::exibirInformacoes();
    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& disciplina : disciplinasMonitoradas) {
        std::cout << "- " << disciplina << "\n";
    }
}

void Monitor::gerarRelatorio() const {
    std::cout << "Relatório do Monitor:\n";
    relatorio.gerarRelatorio();
    exibirInformacoes();
}
