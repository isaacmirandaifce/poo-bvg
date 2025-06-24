#include "Professor.h"

Professor::Professor() : Usuario(), areaDeAtuacao("Desconhecida") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "[Professor] " << nome << " - Área: " << areaDeAtuacao << std::endl;
    std::cout << "Disciplinas: ";
    for (const auto& d : disciplinasMinistradas)
        std::cout << d << ", ";
    std::cout << "\n";
}