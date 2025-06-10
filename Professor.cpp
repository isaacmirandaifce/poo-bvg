#include "Professor.h"
#include <iostream>

Professor::Professor()
    : Usuario(), areaDeAtuacao(""), disciplinasMinistradas() {}

Professor::Professor(const std::string& nome, const std::string& email,
                   const std::string& area, const std::vector<std::string>& disciplinas)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area), disciplinasMinistradas(disciplinas) {}

void Professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome << "\nÁrea de Atuação: " << areaDeAtuacao << "\nDisciplinas Ministradas:\n";
    for (const auto& disc : disciplinasMinistradas) {
        std::cout << "- " << disc << "\n";
    }
    std::cout << std::endl;
}
