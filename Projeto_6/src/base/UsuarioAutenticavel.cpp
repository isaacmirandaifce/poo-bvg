#include "UsuarioAutenticavel.h"
#include <functional>
#include <sstream>

UsuarioAutenticavel::UsuarioAutenticavel(int id, const std::string& username, const std::string& senha)
    : Usuario(id, username), senhaHash(gerarHash(senha)) {
}

std::string UsuarioAutenticavel::gerarHash(const std::string& senha) {
    // std::hash apenas para fins didaticos (nao usar em producao real).
    // O objetivo aqui e demonstrar que a senha em texto puro nunca fica
    // armazenada como estado do objeto.
    std::hash<std::string> hasher;
    std::size_t valorHash = hasher(senha);

    std::ostringstream oss;
    oss << std::hex << valorHash;
    return oss.str();
}
