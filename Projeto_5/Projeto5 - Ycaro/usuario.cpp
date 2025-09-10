#include "usuario.h"

usuario::usuario() {}

usuario::usuario(std::string nome, std::string email, std::string tipo)
    : nome(nome), email(email), tipo(tipo) {}

usuario::~usuario() {}