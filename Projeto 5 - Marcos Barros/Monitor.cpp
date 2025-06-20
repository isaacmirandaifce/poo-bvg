#include "Monitor.h"
#include <iostream>

Monitor::Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string area)
    : Usuario(nome, email, "Monitor"), Aluno(nome, email, matricula, curso), Professor(nome, email, area) {}

void Monitor::adicionarDisciplinaMonitorada(std::string disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::gerarRelatorio() const {
    std::cout << "Monitor: " << Aluno::nome << "\nCurso: " << Aluno::curso << "\nÁrea: " << Professor::areaDeAtuacao << "\n";
    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& d : disciplinasMonitoradas)
        std::cout << "- " << d << "\n";
}
