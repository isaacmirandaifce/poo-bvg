#include "Usuario.h"

Usuario::Usuario(const std::string& nome, const std::string& email, TipoUsuario tipo)
    : nome(nome), email(email), tipo(tipo) {}

Usuario::~Usuario() {}

std::string Usuario::getNome() const { return nome; }
std::string Usuario::getEmail() const { return email; }
TipoUsuario Usuario::getTipo() const { return tipo; }