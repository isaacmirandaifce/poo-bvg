#include "Usuario.h"

Usuario::Usuario() : nome(""), email(""), tipo("") {}

Usuario::Usuario(std::string nome, std::string email, std::string tipo)
    : nome(nome), email(email), tipo(tipo) {}