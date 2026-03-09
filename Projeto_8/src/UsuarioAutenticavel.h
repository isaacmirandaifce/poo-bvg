#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(std::string nome, std::string email, TipoUsuario tipo, std::string senha);
    virtual ~UsuarioAutenticavel() = default;

    virtual bool autenticar(std::string senha) const = 0;
    std::string getSenha() const { return senha; }
};

#endif
