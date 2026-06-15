#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "Usuario.h"
#include "../models/TipoUsuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(int id, const std::string& username, const std::string& senha);

    virtual ~UsuarioAutenticavel() = default;

    virtual bool autenticar(const std::string& senhaInformada) const = 0;

    virtual std::string getNivelAcesso() const = 0;

    virtual TipoUsuario getTipo() const = 0;
};

#endif