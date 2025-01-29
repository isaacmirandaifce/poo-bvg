#include "Professor.h"
#include <iostream>

Professor::Professor() : UsuarioAutenticavel(), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& senha,
                     const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinas)
    : UsuarioAutenticavel(nome, email, senha), areaDeAtuacao(areaDeAtuacao), disciplinasMinistradas(disciplinas) {}

bool Professor::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void Professor::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Área de Atuação: " << areaDeAtuacao << "\n";
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor:\n";
    exibirInformacoes();
    std::cout << "Disciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << "- " << disciplina << "\n";
    }
}