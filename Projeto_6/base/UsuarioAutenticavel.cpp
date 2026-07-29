#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(int id, std::string username, std::string senha, TipoUsuario tipo)
    : id(id), username(username), senhaHash(senha), tipo(tipo) {}

int UsuarioAutenticavel::getId() const {
    return id;
}

std::string UsuarioAutenticavel::getUsername() const {
    return username;
}

TipoUsuario UsuarioAutenticavel::getTipo() const {
    return tipo;
}

std::string UsuarioAutenticavel::tipoToString() const {
    switch (tipo) {
        case TipoUsuario::ADMIN: return "ADMIN";
        case TipoUsuario::AUDITOR: return "AUDITOR";
        case TipoUsuario::OPERADOR: return "OPERADOR";
        default: return "DESCONHECIDO";
    }
}