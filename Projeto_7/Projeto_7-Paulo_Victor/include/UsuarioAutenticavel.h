#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>

class UsuarioAutenticavel {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(std::string senha);
    virtual bool autenticar(std::string senha) const = 0; // Método abstrato
};

#endif