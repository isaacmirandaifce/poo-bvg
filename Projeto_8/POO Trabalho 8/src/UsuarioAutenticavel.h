#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"
#include <string>

class UsuarioAutenticavel : public Usuario {
public:
    UsuarioAutenticavel();
    UsuarioAutenticavel(const std::string& nome, const std::string& email, TipoUsuario tipo);
    virtual ~UsuarioAutenticavel();

    virtual bool autenticar(const std::string& senha) const = 0;

protected:
    static std::size_t hashSenha(const std::string& senha);
};

#endif // USUARIO_AUTENTICAVEL_H
