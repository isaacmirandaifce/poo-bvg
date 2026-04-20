#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(string nome, string email, string tipo) {
    this->nome = nome;
    this->email = email;
    this->tipo = tipo;
}
