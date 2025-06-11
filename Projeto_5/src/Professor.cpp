#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(std::string nome, std::string email, std::string area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor:\n"
              << "Nome: " << nome << "\n"
              << "Área de Atuação: " << areaDeAtuacao << "\n"
              << "Disciplinas Ministradas: ";
    for (const auto& disc : disciplinasMinistradas)
        std::cout << disc << " ";
    std::cout << "\n";
}
