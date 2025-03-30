#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"
#include <string>

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& senha)
        : Usuario(nome, email, tipo), senha(senha) {}

    virtual bool autenticar(const std::string& senhaTentativa) const = 0;
};

#endif // USUARIO_AUTENTICAVEL_H
