#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& email, const std::vector<std::string>& disciplinas)
    : UsuarioAutenticavel(nome, email, "senhaProf"), disciplinas(disciplinas) {}

void Professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome << "\nDisciplinas:\n";
    for (const auto& disciplina : disciplinas) {
        std::cout << "- " << disciplina << "\n";
    }
}

bool Professor::autenticar(const std::string& senha) {
    return senha == this->senha;
}