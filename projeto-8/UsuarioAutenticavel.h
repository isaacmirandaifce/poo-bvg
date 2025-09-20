#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
private:
    std::string senha;

public:
    UsuarioAutenticavel(std::string nome, std::string email, TipoUsuario tipo, std::string senha);
    virtual ~UsuarioAutenticavel() {}
    virtual bool autenticar(const std::string& senha) = 0;

protected:
    const std::string& getSenha() const;
};

#endif // USUARIO_AUTENTICAVEL_H
