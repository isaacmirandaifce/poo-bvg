#include "Monitor.h"
#include <iostream>

Monitor::Monitor(std::string nome, std::string email, std::string senha,
                 std::string matricula, std::string curso, std::string area)
    : Aluno(nome, email, senha, matricula, curso),
      Professor(nome, email, area) {}

void Monitor::gerarRelatorio() const {
    std::cout << "=== Relatório do Monitor ===\n";
    Aluno::gerarRelatorio();
    std::cout << "Área como professor: " << areaDeAtuacao << "\n";
}