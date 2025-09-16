
#include "../include/Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string login, std::string senha)
    : UsuarioAutenticavel(nome, login, senha) {}

bool Professor::autenticar(std::string senhaTentativa) {
    return senha == senhaTentativa;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor: " << nome << std::endl;
}
