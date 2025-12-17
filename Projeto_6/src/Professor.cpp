#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& nome,
                     const std::string& email,
                     const std::string& senha)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha) {}

bool Professor::autenticar(const std::string& senhaInformada) const {
    return senha == senhaInformada;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor: " << nome << std::endl;
}