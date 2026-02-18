#include "Usuario.h"

Usuario::Usuario(std::string nome, std::string email, TipoUsuario tipo)
    : nome(nome), email(email), tipo(tipo) {}

std::string Usuario::getNome() const { return nome; }
std::string Usuario::getEmail() const { return email; }
TipoUsuario Usuario::getTipo() const { return tipo; }
