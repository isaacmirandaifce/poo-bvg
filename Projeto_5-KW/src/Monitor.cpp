#include "Monitor.h"
#include <iostream>

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& area)
    : Usuario(nome, email, "Monitor"), Aluno(nome, email, matricula, curso), Professor(nome, email, area) {}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::gerarRelatorio() const {
    std::cout << "Relatório do Monitor:\n";
    std::cout << "Nome: " << Aluno::nome << "\nMatrícula: " << matricula << "\nCurso: " << curso << "\n";
    std::cout << "Área de Atuação: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& disc : disciplinasMonitoradas) {
        std::cout << "- " << disc << "\n";
    }
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas monitoradas por " << Aluno::nome << ":\n";
    for (const auto& disc : disciplinasMonitoradas) {
        std::cout << "- " << disc << "\n";
    }
}