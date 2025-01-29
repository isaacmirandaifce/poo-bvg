#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel();
    UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& senha);

    virtual bool autenticar(const std::string& senha) const = 0;
};

#endif 