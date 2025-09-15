#include "UsuarioAutenticavel.h"
#include <functional>

UsuarioAutenticavel::UsuarioAutenticavel(const std::string& nome, const std::string& email,
                                       int id, TipoUsuario tipo, const std::string& senha)
    : Usuario(nome, email, id, tipo) {
    setSenha(senha);
}

void UsuarioAutenticavel::setSenha(const std::string& senha) {
    senhaHash = gerarHash(senha);
}

std::string UsuarioAutenticavel::gerarHash(const std::string& senha) const {
    // Hash simples para demonstração (em produção usar bibliotecas adequadas)
    std::hash<std::string> hasher;
    return std::to_string(hasher(senha + "salt123"));
}
