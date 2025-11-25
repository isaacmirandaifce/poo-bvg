#include "Usuario.h"

Usuario::Usuario() : nome(""), email(""), tipo("") {}

Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
    : nome(nome), email(email), tipo(tipo) {}

Usuario::~Usuario() {}

const std::string& Usuario::getNome() const {
    return nome;
}

const std::string& Usuario::getEmail() const {
    return email;
}

const std::string& Usuario::getTipo() const {
    return tipo;
}
