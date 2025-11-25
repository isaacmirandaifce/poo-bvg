#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario("", "", "Professor"), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome,
                     const std::string& email,
                     const std::string& areaDeAtuacao,
                     const std::vector<std::string>& disciplinas)
    : Usuario(nome, email, "Professor"),
      areaDeAtuacao(areaDeAtuacao),
      disciplinasMinistradas(disciplinas) {}

void Professor::gerarRelatorio() const {
    std::cout << "[Professor] Nome: " << nome
              << " | Área: " << areaDeAtuacao << std::endl;

    if (!disciplinasMinistradas.empty()) {
        std::cout << "Disciplinas ministradas:" << std::endl;
        for (const auto& d : disciplinasMinistradas) {
            std::cout << "- " << d << std::endl;
        }
    }
}

void Professor::adicionarDisciplinaMinistrada(const std::string& nomeDisciplina) {
    disciplinasMinistradas.push_back(nomeDisciplina);
}
