#include "Monitor.h"
#include <iostream>

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& matricula, 
                 const std::string& curso, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Monitor"), Aluno(nome, email, matricula, curso), Professor(nome, email, areaDeAtuacao) {}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas Monitoradas pelo Monitor " << nome << ":\n";
    for (const auto& disciplina : disciplinasMinistradas) { // Herdado de Professor
        std::cout << "- " << disciplina << "\n";
    }
}

void Monitor::gerarRelatorio() const {
    std::cout << "Relatório do Monitor:\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Matrícula: " << matricula << "\nCurso: " << curso << "\n";
    std::cout << "Área de Atuação: " << areaDeAtuacao << "\n";

    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << "- " << disciplina << "\n";
    }

    std::cout << "Disciplinas Cursadas:\n";
    for (const auto& disciplina : disciplinasCursadas) { // Herdado de Aluno
        std::cout << "- " << disciplina << "\n";
    }
}
