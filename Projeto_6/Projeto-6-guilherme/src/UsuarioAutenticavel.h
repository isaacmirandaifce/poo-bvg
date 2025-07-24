#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel();
    UsuarioAutenticavel(std::string nome, std::string email, std::string tipo, std::string senha);

    virtual bool autenticar(std::string senhaDigitada) const = 0;
};

#endif