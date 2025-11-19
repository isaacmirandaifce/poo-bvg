#include "UsuarioAutenticavel.h"
#include <functional>

UsuarioAutenticavel::UsuarioAutenticavel() : Usuario() {}
UsuarioAutenticavel::UsuarioAutenticavel(const std::string& nome, const std::string& email, TipoUsuario tipo)
    : Usuario(nome, email, tipo) {}
UsuarioAutenticavel::~UsuarioAutenticavel() {}

std::size_t UsuarioAutenticavel::hashSenha(const std::string& senha) {
    // Implementação simples: usa std::hash para evitar armazenar senha em texto claro.
    return std::hash<std::string>{}(senha);
}
