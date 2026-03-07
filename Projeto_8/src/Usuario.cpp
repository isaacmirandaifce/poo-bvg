#include "../include/Usuario.h"

Usuario::Usuario(std::string nome, TipoUsuario tipo)
    : nome(nome), tipo (tipo) {}

std::string Usuario::getNome() const {
    return nome;
}

TipoUsuario Usuario::getTipo() const {
    return tipo;
}