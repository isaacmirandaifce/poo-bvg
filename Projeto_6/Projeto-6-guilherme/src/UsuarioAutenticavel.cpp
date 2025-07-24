#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel()
    : Usuario(), senha("") {}

UsuarioAutenticavel::UsuarioAutenticavel(std::string nome, std::string email, std::string tipo, std::string senha)
    : Usuario(nome, email, tipo), senha(senha) {}