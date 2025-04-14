#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include "Usuario.h"
#include <string>

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& senha);
    virtual bool autenticar(const std::string& senha) = 0;
    virtual ~UsuarioAutenticavel() = default;
};

#endif // USUARIOAUTENTICAVEL_H