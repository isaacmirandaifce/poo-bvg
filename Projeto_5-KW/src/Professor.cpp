#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor:\n";
    std::cout << "Nome: " << nome << "\nÁrea de Atuação: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas ministradas:\n";
    for (const auto& disc : disciplinasMinistradas) {
        std::cout << "- " << disc << "\n";
    }
}