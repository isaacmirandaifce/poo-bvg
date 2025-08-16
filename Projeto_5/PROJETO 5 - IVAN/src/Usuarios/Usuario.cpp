#include "Usuario.h"

Usuario::Usuario() : nome(""), email(""), tipo("") {}

Usuario::Usuario(string nome, string email, string tipo) 
    : nome(nome), email(email), tipo(tipo) {}

Usuario::~Usuario() {}