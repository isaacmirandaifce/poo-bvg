#include <iostream>         // Adicionado!
#include "Monitor.h"

Monitor::Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string area)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, area) {}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas monitoradas:\n";
    for (const auto& d : disciplinasMonitoradas)
        std::cout << "- " << d << std::endl;
}

void Monitor::gerarRelatorio() const {  
    std::cout << "Relatorio do Monitor: " << nome << "\n";
    std::cout << "Curso: " << curso << "\n";
    std::cout << "Area de atuacao: " << areaDeAtuacao << "\n";
}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}
