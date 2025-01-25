#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(const std::string& nome, const std::string& senha)
    : nome(nome), senha(senha) {}

std::string UsuarioAutenticavel::getNome() const {
    return nome;
}
