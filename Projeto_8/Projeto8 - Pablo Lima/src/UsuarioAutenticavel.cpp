#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& senha)
    : Usuario(nome, email), senha(senha) {}