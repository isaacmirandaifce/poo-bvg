#include "monitor.h"
#include <iostream>

// Construtor com inicialização das classes base Aluno e Professor
Monitor::Monitor(std::string nome, std::string email,
                 std::string matricula, std::string curso,
                 std::string area)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, area) {}

void Monitor::adicionarDisciplinaMonitorada(std::string d) {
    disciplinasMonitoradas.push_back(d);
}

void Monitor::gerarRelatorio() const {
    std::cout << "\n=== Relatório do Monitor ===\n";
    std::cout << "Nome: " << nome << "\nCurso: " << curso;
    std::cout << "\nÁrea: " << areaDeAtuacao << "\n";

    std::cout << "Disciplinas monitoradas: ";
    for (auto &d : disciplinasMonitoradas) std::cout << d << ", ";
    std::cout << "\n";
}
