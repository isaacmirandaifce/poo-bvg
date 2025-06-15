#include "Professor.hpp"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {
    tipo = "Professor";
}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatorio do Professor\n";
    std::cout << "Nome: " << nome << "\nArea de Atuacao: " << areaDeAtuacao << "\nDisciplinas Ministradas:\n";
    for (const auto& d : disciplinasMinistradas) {
        std::cout << "- " << d << "\n";
    }
    std::cout << "----------------------\n";
}

std::string Professor::getAreaDeAtuacao() const {
    return areaDeAtuacao;
}
