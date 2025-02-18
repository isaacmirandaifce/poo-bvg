#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"
#include <string>

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    // Construtor atualizado
    UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& senha, TipoUsuario tipo);

    virtual ~UsuarioAutenticavel() = default;

    // Método abstrato
    virtual bool autenticar(const std::string& senha) const = 0;
};

#endif
