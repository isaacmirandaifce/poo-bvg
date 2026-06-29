#include "UsuarioAutenticavel.h"

Usuario::Usuario(int id, std::string username) : id(id), username(username) {}

int Usuario::getId() const {
    return id;
};

std::string Usuario::getUsername() const {
    return username;
}

UsuarioAutenticavel::UsuarioAutenticavel(int id, std::string username, TipoUsuario tipo) : Usuario(id, username), tipo(tipo) {}

TipoUsuario UsuarioAutenticavel::getTipo() const {
    return tipo;
}
