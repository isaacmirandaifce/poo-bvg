#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h"

class Usuario {
protected:
    std::string nome;
    std::string email;
    TipoUsuario tipo;

public:
    Usuario(std::string nome, std::string email, TipoUsuario tipo);
    virtual ~Usuario();

    std::string getNome() const;
    std::string getEmail() const;
    TipoUsuario getTipo() const;
};

#endif