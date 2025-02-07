#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>

class UsuarioAutenticavel {
public:
    virtual ~UsuarioAutenticavel() = default;
    virtual bool autenticar(const std::string& senha) const = 0;
};

#endif 