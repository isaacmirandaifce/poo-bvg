#include "Professor.h"

Professor::Professor()
    : Usuario("", "", "Professor"), areaDeAtuacao(""), disciplinasMinistradas() {
    tipo = "Professor";
}

Professor::Professor(const std::string& nome,
                     const std::string& email,
                     const std::string& areaDeAtuacao,
                     const std::vector<std::string>& disciplinasMinistradas)
    : Usuario(nome, email, "Professor"),
      areaDeAtuacao(areaDeAtuacao),
      disciplinasMinistradas(disciplinasMinistradas) {}

void Professor::gerarRelatorio() const {
    std::cout << "===== RELATORIO (PROFESSOR) =====\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Area de atuacao: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas ministradas:\n";
    for (const auto& d : disciplinasMinistradas) {
        std::cout << " - " << d << "\n";
    }
    std::cout << "===============================\n\n";
}

std::string Professor::getAreaDeAtuacao() const { return areaDeAtuacao; }
