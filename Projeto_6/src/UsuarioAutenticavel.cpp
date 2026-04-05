#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(std::string nome, std::string matricula,
                                         TipoUsuario tipo, std::string senha)
    : Usuario(nome, matricula, tipo), senha(senha) {}
