#include "../include/Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

void Professor::gerarRelatorio() const {
    std::cout << "Relatorio do Professor:\n"
              << "Nome: " << nome << "\n"
              << "Area de Atuacao: " << areaDeAtuacao << "\n"
              << "Disciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << " - " << disciplina << "\n";
    }
}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}