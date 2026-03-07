#include "../include/UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(
    std::string nome,
    TipoUsuario tipo,
    std::string senha
) : Usuario(nome, tipo), senha(senha) {}