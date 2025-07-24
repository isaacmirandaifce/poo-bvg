#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {
    tipo = "Professor";
}

Professor::Professor(std::string nome, std::string email, std::string area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

void Professor::adicionarDisciplina(std::string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "=== Relatório do Professor ===\n"
              << "Nome: " << nome << "\n"
              << "Área: " << areaDeAtuacao << "\n"
              << "Disciplinas Ministradas:\n";

    for (const auto& d : disciplinasMinistradas) {
        std::cout << "- " << d << "\n";
    }
}
