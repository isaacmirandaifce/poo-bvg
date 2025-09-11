#include "Professor.h"
#include <iostream>

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

void Professor::gerarRelatorio() const {
    std::cout << "Nome: " << nome << "\nÁrea de Atuação: " << areaDeAtuacao << std::endl;
}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}
