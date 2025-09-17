#include "Usuario.h"

Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
    : nome(nome), email(email), tipo(tipo) {}

std::string Usuario::getNome() const { return nome; }
std::string Usuario::getEmail() const { return email; }
std::string Usuario::getTipo() const { return tipo; }