#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor:\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Área de Atuação: " << areaDeAtuacao << "\nDisciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << "- " << disciplina << "\n";
    }
}
