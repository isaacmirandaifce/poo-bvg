#include "Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string email, std::string area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

void Professor::adicionarDisciplina(std::string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "--- Relatorio de Professor ---" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Area de Atuacao: " << areaDeAtuacao << std::endl;
    std::cout << "Disciplinas Ministradas: ";
    for (const auto& d : disciplinasMinistradas) {
        std::cout << d << " ";
    }
    std::cout << "\n-----------------------------" << std::endl << std::endl;
}