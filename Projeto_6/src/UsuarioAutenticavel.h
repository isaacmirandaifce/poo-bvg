#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;
public:
    UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& senha)
        : Usuario(nome, email), senha(senha) {}

    virtual ~UsuarioAutenticavel() = default;

    virtual bool autenticar(const std::string& tentativaSenha) const = 0;

    void setSenha(const std::string& novaSenha) {
        senha = novaSenha;
    }

    std::string getSenha() const {
        return senha;
    }
};

#endif // USUARIO_AUTENTICAVEL_H
