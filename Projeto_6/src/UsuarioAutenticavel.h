#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H
#include <string>
#include "enums.h"
class UsuarioAutenticavel {
protected:
    std::string nome;
    std::string senha;
    TipoUsuario tipo;
public:
    UsuarioAutenticavel() = default;
    UsuarioAutenticavel(std::string n, std::string s, TipoUsuario t)
        : nome(n), senha(s), tipo(t) {}
    virtual bool autenticar(const std::string& s) = 0;
    virtual ~UsuarioAutenticavel() = default;
};
#endif
