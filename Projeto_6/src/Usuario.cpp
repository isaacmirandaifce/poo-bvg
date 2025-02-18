#include "Usuario.h"

Usuario::Usuario(const string& nome, const string& email, TipoUsuario tipo) 
    : nome(nome), email(email), tipo(tipo) {}

string Usuario::getNome() const {
    return nome;
}

string Usuario::getEmail() const {
    return email;
}

TipoUsuario Usuario::getTipo() const {
    return tipo;
}
