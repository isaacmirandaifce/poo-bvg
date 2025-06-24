#include "Usuario.h"

Usuario::Usuario() : nome("Desconhecido"), email("sem@email.com"), tipo("Indefinido") {}

Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
    : nome(nome), email(email), tipo(tipo) {}

Usuario::~Usuario() {}