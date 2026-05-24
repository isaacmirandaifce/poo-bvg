#include "Usuario.h"

Usuario::Usuario() {
    nome = "";
    email = "";
    tipo = "";
}

Usuario::Usuario(string nome, string email, string tipo) {
    this->nome = nome;
    this->email = email;
    this->tipo = tipo;
}

Usuario::~Usuario() {
}