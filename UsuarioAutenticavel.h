#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(std::string nome, TipoUsuario tipo, std::string senha)
        : Usuario(nome, tipo), senha(senha) {}

    virtual bool autenticar(std::string senhaDigitada) const = 0;

    virtual ~UsuarioAutenticavel() {}
};

#endif
