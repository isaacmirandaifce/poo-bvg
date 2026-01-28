#include <iostream>
#include "../include/Professor.h"

Professor::Professor(std::string nome, std::string senha)
    : UsuarioAutenticavel(nome, TipoUsuario::PROFESSOR, senha) {}

bool Professor::autenticar(std::string senha) const {
    return this->senha == senha;
}

void Professor::gerarRelatorio() const {
    std::cout << "\n=== Relatório do Professor ===\n";
    std::cout << "Nome: " << nome << "\n";
}