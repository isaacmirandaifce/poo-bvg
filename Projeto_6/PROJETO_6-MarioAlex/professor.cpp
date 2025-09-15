#include "Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string email, std::string senha, std::string disciplina)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha),
      disciplinaPrincipal(disciplina) {}

bool Professor::autenticar(std::string senhaDigitada) const {
    return senhaDigitada == senha;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatorio do Professor: " << nome << "\n";
    std::cout << "Disciplina Principal: " << disciplinaPrincipal << "\n";
}