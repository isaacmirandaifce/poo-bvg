#include "usuario.h"
// Construtor padrão
Usuario::Usuario() : nome(""), email(""), tipo("") {}
// Construtor com parâmetros
Usuario::Usuario(std::string nome, std::string email, std::string tipo)
    : nome(nome), email(email), tipo(tipo) {}
