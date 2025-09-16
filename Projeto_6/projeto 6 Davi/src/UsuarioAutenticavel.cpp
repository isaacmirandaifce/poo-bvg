
#include "../include/UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(std::string nome, std::string login, std::string senha)
    : Usuario(nome, login), senha(senha) {}
