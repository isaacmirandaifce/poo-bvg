#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(std::string n, std::string e, std::string t, std::string area, std::vector<std::string> disc)
    : Usuario(n, e, t), areaDeAtuacao(area), disciplinasMinistradas(disc) {}

void Professor::gerarRelatorio() {
    std::cout << "--- RELATORIO DE PROFESSOR ---" << std::endl;
    std::cout << "Nome: " << nome << " | Area: " << areaDeAtuacao << std::endl;
    std::cout << "Disciplinas Ministradas: ";
    for(const auto& d : disciplinasMinistradas) std::cout << "{" << d << "} ";
    std::cout << "\n------------------------------" << std::endl;
}