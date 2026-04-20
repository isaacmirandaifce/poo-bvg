#include "Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string matricula, std::string senha)
    : UsuarioAutenticavel(nome, matricula, TipoUsuario::PROFESSOR, senha) {}

bool Professor::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor: " << nome << std::endl;
}
