#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& senha)
    : nome(nome), senha(senha) {}

bool Professor::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor: " << nome << std::endl;
}

TipoUsuario Professor::getTipo() const {
    return TipoUsuario::PROFESSOR;
}