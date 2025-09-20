#include "Usuario.h"

Usuario::Usuario(std::string nome, std::string email, TipoUsuario tipo)
    : nome(nome), email(email), tipo(tipo) {
}

const std::string& Usuario::getNome() const {
    return this->nome;
}

const std::string& Usuario::getEmail() const {
    return this->email;
}
