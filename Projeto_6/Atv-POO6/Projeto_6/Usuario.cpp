#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
    : nome(nome), email(email), tipo(tipo) {}
