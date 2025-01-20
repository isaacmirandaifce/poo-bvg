#include "../include/professor.h"
#include <iostream>

// Construtor padrão
Professor::Professor() : Usuario("", "", "Professor"), areaDeAtuacao("") {}

// Construtor parametrizado
Professor::Professor(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

// Método para adicionar uma disciplina ministrada
void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

// Sobrescrita de gerarRelatorio
void Professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome << "\n"
              << "Area de Atuacao: " << areaDeAtuacao << "\n"
              << "Disciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << "  - " << disciplina << "\n";
    }
}
