#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"
#include <string>

class UsuarioAutenticavel : public Usuario {
private:
    std::string senha;

protected:
    bool verificarSenha(const std::string& senha) const; // Método protegido

public:
    // Construtores
    UsuarioAutenticavel();
    UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& senha);

    // Método abstrato
    virtual bool autenticar(const std::string& senha) const = 0;

    // Destrutor virtual
    virtual ~UsuarioAutenticavel() {}
};

#endif // USUARIO_AUTENTICAVEL_H
