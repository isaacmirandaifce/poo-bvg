#include "Usuario.h"

Usuario::Usuario() : nome(""), email(""), tipo("") {}

Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
    : nome(nome), email(email), tipo(tipo) {}
