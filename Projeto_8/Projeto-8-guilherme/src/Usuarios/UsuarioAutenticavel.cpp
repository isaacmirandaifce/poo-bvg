#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel() : Usuario(), senha("") {}

UsuarioAutenticavel::UsuarioAutenticavel(string nome, string email, string tipo, string senha)
    : Usuario(nome, email, tipo), senha(senha) {}