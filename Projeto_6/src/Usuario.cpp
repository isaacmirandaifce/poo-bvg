#include "Usuario.h"

Usuario::Usuario(std::string nome, std::string matricula, TipoUsuario tipo)
    : nome(nome), matricula(matricula), tipo(tipo) {}

std::string Usuario::getNome() const {
    return nome;
}

TipoUsuario Usuario::getTipo() const {
    return tipo;
}
