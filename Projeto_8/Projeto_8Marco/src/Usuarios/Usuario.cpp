#include "Usuario.h"

Usuario::Usuario() : nome(""), email(""), tipo("") {}

Usuario::Usuario(string nome, string email, string tipo)
    : nome(nome), email(email), tipo(tipo) {}

Usuario::~Usuario() {}

string Usuario::getNome() const {
    return nome;
}

string Usuario::getEmail() const {
    return email;
}

string Usuario::getTipo() const {
    return tipo;
}
