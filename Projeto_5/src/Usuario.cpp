#include "Usuario.h"
#include <iostream>

Usuario::Usuario() : nome(""), email(""), tipo("Desconhecido") {}

Usuario::Usuario(std::string nome, std::string email, std::string tipo)
    : nome(nome), email(email), tipo(tipo) {}

Usuario::~Usuario() {}
