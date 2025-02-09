#include "../include/UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel() : Usuario(), senha("") {}

UsuarioAutenticavel::UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& senha)
    : Usuario(nome, email, tipo), senha(senha) {}

bool UsuarioAutenticavel::verificarSenha(const std::string& senha) const {
    return this->senha == senha;
}
