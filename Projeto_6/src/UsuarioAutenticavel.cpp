#include "UsuarioAutenticavel.h"
#include <functional>

UsuarioAutenticavel::UsuarioAutenticavel() : Usuario(), senhaHash("") {}

UsuarioAutenticavel::UsuarioAutenticavel(std::string nome, std::string email, TipoUsuario tipo, const std::string& senha)
    : Usuario(nome, email, tipo), senhaHash(hashSenha(senha)) {}

UsuarioAutenticavel::~UsuarioAutenticavel() {}

// Hash simples (didatico) apenas para evitar guardar a senha em texto puro.
// Em um sistema real, usar uma biblioteca de hash criptografico (ex.: bcrypt).
std::string UsuarioAutenticavel::hashSenha(const std::string& senha) {
    std::size_t valor = std::hash<std::string>{}(senha);
    return std::to_string(valor);
}

void UsuarioAutenticavel::definirSenha(const std::string& senha) {
    senhaHash = hashSenha(senha);
}

bool UsuarioAutenticavel::validarSenha(const std::string& senha) const {
    return senhaHash == hashSenha(senha);
}
