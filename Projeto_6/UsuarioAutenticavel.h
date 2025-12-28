#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>

class UsuarioAutenticavel {
public:
    virtual bool autenticar(const std::string& senha) = 0;
    virtual ~UsuarioAutenticavel() = default;
};

#endif
