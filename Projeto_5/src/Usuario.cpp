#include "Usuario.h"

/* Construtor padrão */
Usuario::Usuario() : nome(""), email(""), tipo("") {}

/* Construtor parametrizado */
Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
    : nome(nome), email(email), tipo(tipo) {}

/* Destrutor virtual */
Usuario::~Usuario() {
    // Implementação vazia, mas necessária
}
