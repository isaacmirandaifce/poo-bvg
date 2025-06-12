#include "Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string email, std::string area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome << "\narea de atuacao: " << areaDeAtuacao
              << "\nDisciplinas ministradas:\n";
    for (const auto& d : disciplinasMinistradas)
        std::cout << "- " << d << "\n";
}
