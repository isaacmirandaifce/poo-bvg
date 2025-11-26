#include "Usuario.h"

Usuario::Usuario() : nome("Sem nome"), email("N/A"), tipo("Usuario") {}

Usuario::Usuario(const string &nome, const string &email, const string &tipo)
    : nome(nome), email(email), tipo(tipo) {}

Usuario::~Usuario() {}

string Usuario::getNome() const { return nome; }
string Usuario::getEmail() const { return email; }
string Usuario::getTipo() const { return tipo; }