#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h"

class Usuario {
protected:
    std::string nome;
    std::string matricula;
    TipoUsuario tipo;

public:
    Usuario(std::string nome, std::string matricula, TipoUsuario tipo);
    virtual ~Usuario() = default;

    std::string getNome() const;
    TipoUsuario getTipo() const;
};

#endif
