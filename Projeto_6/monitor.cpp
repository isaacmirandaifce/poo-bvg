#include "Monitor.h"
#include <iostream>

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& areaDeAtuacao, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "MONITOR", senha) {}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::gerarRelatorio() const {
    std::cout << "Relatório do Monitor\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Disciplinas Monitoradas: ";
    for (const auto& disc : disciplinasMonitoradas) {
        std::cout << disc << " ";
    }
    std::cout << "\n";
}