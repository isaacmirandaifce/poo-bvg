#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(std::string nome, std::string email, TipoUsuario tipo, std::string senha);
    virtual ~UsuarioAutenticavel();

    // Método virtual puro exigido pelo projeto
    virtual bool autenticar(std::string senhaDigitada) = 0;
};

#endif
