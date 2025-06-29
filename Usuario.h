#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h"

class Usuario {
protected:
    std::string nome;
    TipoUsuario tipo;

public:
    Usuario(std::string nome, TipoUsuario tipo) : nome(nome), tipo(tipo) {}

    std::string getNome() const { return nome; }
    TipoUsuario getTipo() const { return tipo; }

    virtual ~Usuario() {}
};

#endif
