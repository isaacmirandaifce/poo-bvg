#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(std::string n, std::string e, std::string s, TipoUsuario t)
    : Usuario(n, e), senha(s), tipo(t) {}
