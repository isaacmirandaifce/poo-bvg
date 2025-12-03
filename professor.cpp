#include "professor.h"
#include <iostream>

Professor::Professor() {}

// Construtor com inicialização da classe base Usuario
Professor::Professor(std::string nome, std::string email, std::string area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

void Professor::adicionarDisciplinaMinistrada(std::string d) {
    disciplinasMinistradas.push_back(d);
}
// classe Professor sobrescreve o método virtual puro gerarRelatorio
void Professor::gerarRelatorio() const {
    std::cout << "\n=== Relatório do Professor ===\n";
    std::cout << "Nome: " << nome << "\nÁrea: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas ministradas: ";
    for (auto &d : disciplinasMinistradas) std::cout << d << ", ";
    std::cout << "\n";
}
