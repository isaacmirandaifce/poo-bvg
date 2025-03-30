#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinas)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao), disciplinasMinistradas(disciplinas) {}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor:\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Área de Atuação: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << " - " << disciplina << "\n";
    }
}
