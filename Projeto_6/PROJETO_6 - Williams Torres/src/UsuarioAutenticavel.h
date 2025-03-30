#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>

class UsuarioAutenticavel {
protected:
    std::string nome;
    std::string senha;

public:
    UsuarioAutenticavel(const std::string& nome, const std::string& senha);
    virtual ~UsuarioAutenticavel() = default;

    virtual bool autenticar(const std::string& senha) const = 0;

    std::string getNome() const;
};

#endif // USUARIO_AUTENTICAVEL_H