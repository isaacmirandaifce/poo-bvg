#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel() : Usuario() {
    senha = "123";
}

UsuarioAutenticavel::UsuarioAutenticavel(string nome, string email, TipoUsuario tipo, string senha)
    : Usuario(nome, email, tipo) {
    this->senha = senha;
}

//  IMPLEMENTAÇÃO DOS GETTERS

string UsuarioAutenticavel::getSenha() const {
    return senha;
}

string UsuarioAutenticavel::getNome() const {
    return nome;   // vem da classe Usuario
}

string UsuarioAutenticavel::getEmail() const {
    return email;  // vem da classe Usuario
}
