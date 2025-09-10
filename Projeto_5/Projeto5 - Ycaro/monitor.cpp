#include "monitor.h"
#include <iostream>

monitor::monitor() : aluno(), professor() {}

monitor::monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string areaDeAtuacao)
    : aluno(nome, email, matricula, curso), professor(nome, email, areaDeAtuacao) {}

void monitor::adicionarDisciplinaMonitorada(std::string disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void monitor::gerarRelatorio() const {
    std::cout << "Monitor: " << nome << "\nMatrícula: " << matricula
              << "\nCurso: " << curso << "\narea de Atuacao: " << areaDeAtuacao
              << "\nDisciplinas cursadas:\n";
    for (const auto& d : aluno::disciplinas) {
        std::cout << "- " << d << "\n";
    }
    std::cout << "Disciplinas monitoradas:\n";
    for (const auto& dm : disciplinasMonitoradas) {
        std::cout << "- " << dm << "\n";
    }
}
