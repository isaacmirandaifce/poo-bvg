#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& nome,
                     const std::string& email,
                     const std::string& senha,
                     const std::string& disciplina)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha),
      disciplina(disciplina) {}

bool Professor::autenticar(const std::string& senhaInformada) const {
    return senha == senhaInformada;
}

void Professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome
              << " | Disciplina: " << disciplina << std::endl;
}