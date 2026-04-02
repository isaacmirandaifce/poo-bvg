#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    string senha;

public:
    UsuarioAutenticavel();
    UsuarioAutenticavel(string nome, string email, TipoUsuario tipo, string senha);

    virtual bool autenticar(string senha) = 0;
};

#endif
