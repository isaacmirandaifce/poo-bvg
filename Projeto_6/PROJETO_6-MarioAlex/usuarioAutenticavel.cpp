#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(std::string nome, std::string email, TipoUsuario tipo, std::string senha)
    : Usuario(nome, email, tipo), senha(senha) {}