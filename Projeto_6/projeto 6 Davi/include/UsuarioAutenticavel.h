
#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;
public:
    UsuarioAutenticavel(std::string nome, std::string login, std::string senha);
    virtual bool autenticar(std::string senha) = 0;
};

#endif
