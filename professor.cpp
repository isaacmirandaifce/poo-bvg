#include "professor.h"
#include <iostream>

professor::professor() {}

professor::professor(std::string nome, std::string email, std::string area)
    : usuario(nome, email, "professor"), areaDeAtuacao(area) {}

void professor::adicionarDisciplina(std::string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome << "\narea: " << areaDeAtuacao << "\nDisciplinas ministradas:\n";
    for (const auto& d : disciplinasMinistradas) {
        std::cout << "- " << d << "\n";
    }
}