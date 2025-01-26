#include "Usuario.h"

// Construtor padrão 
Usuario::Usuario() : nome(""), email(""), tipo("") {}

// Construtor para inicializar os atributos com valores fornecidos
Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
    : nome(nome), email(email), tipo(tipo) {}

