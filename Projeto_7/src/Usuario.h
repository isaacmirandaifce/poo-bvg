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
    Usuario(const std::string& nome,
            const std::string& email,
            TipoUsuario tipo);

    virtual ~Usuario() = default;

    std::string getNome() const;
    TipoUsuario getTipo() const;
};

#endif