#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(std::string nome, std::string email, std::string area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

void Professor::adicionarDisciplina(std::string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome << "\nÁrea: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas ministradas:\n";
    for (const auto& d : disciplinasMinistradas)
        std::cout << "- " << d << "\n";
}
