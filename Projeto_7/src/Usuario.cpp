#include "Usuario.h"

Usuario::Usuario() : nome(""), email("") {}

Usuario::Usuario(const std::string& nome, const std::string& email)
    : nome(nome), email(email) {}

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getEmail() const {
    return email;
}