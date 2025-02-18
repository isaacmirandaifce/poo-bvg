#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(const std::string& nome, const std::string& email, 
                                         const std::string& senha, TipoUsuario tipo)
    : Usuario(nome, email, tipo), senha(senha) {}
