#include "Usuario.h"

Usuario::Usuario(std::string nome, std::string cpf, TipoUsuario tipo)
    : nome(nome), cpf(cpf), tipo(tipo) {}

Usuario::~Usuario() {}

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getCpf() const {
    return cpf;
}

TipoUsuario Usuario::getTipo() const {
    return tipo;
}