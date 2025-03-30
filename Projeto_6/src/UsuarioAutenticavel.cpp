#include "../include/UsuarioAutenticavel.h"


UsuarioAutenticavel::UsuarioAutenticavel(const std::string& nome, const std::string& email, TipoUsuario tipo, const std::string& senha)
    : Usuario(nome, email, tipo), senha(senha) {}


std::string UsuarioAutenticavel::getSenha() const {
    return senha;
}

UsuarioAutenticavel::~UsuarioAutenticavel() {} 