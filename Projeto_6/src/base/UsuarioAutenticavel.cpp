#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(
    int id,
    const std::string& username,
    const std::string& senha
) : Usuario(id, username), senha(senha) {}