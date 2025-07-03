#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include "Usuario.h"

class UsuarioAutenticavel : public virtual Usuario {
protected:
    string senha;

public:
    UsuarioAutenticavel();
    UsuarioAutenticavel(string nome, string email, string tipo, string senha);

    virtual bool autenticar(string senhaTentativa) = 0;
};

#endif