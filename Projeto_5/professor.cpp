#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\nÁrea de Atuação: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas Ministradas: ";
    for (const auto& disc : disciplinasMinistradas)
        std::cout << disc << " ";
    std::cout << "\n";
}
