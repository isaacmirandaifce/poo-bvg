#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel() : Usuario() {
    senha = "123";
}

UsuarioAutenticavel::UsuarioAutenticavel(string nome, string email, TipoUsuario tipo, string senha)
    : Usuario(nome, email, tipo) {
    this->senha = senha;
}
