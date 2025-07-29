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

bool Professor::ministraDisciplina(const std::string& disciplina) const {
    for (const auto& d : disciplinasMinistradas) {
        if (d == disciplina) return true;
    }
    return false;
}

void Professor::imprimirInformacoes() const {
    std::cout << "Professor: " << nome << "\nÁrea: " << areaDeAtuacao << "\nDisciplinas: ";
    for (const auto& d : disciplinasMinistradas) {
        std::cout << d << " ";
    }
    std::cout << "\n";
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
