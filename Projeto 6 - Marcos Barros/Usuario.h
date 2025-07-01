#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h"

class Usuario {
protected:
    int id;
    std::string nome;
    TipoUsuario tipo;

public:
    Usuario(int id, std::string nome, TipoUsuario tipo);
    virtual ~Usuario() = default;

    std::string getNome() const;
    int getId() const;
    std::string getTipoAsString() const;
};

#endif // USUARIO_H