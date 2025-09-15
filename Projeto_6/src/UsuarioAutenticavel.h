#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"
#include <string>

class UsuarioAutenticavel : public Usuario {
private:
    std::string senhaHash; // Simulação de hash da senha

protected:
    void setSenha(const std::string& senha);

public:
    UsuarioAutenticavel(const std::string& nome, const std::string& email,
                       int id, TipoUsuario tipo, const std::string& senha);

    virtual ~UsuarioAutenticavel() = default;
    virtual bool autenticar(const std::string& senha) = 0;

    // Método auxiliar para hash simples (apenas para demonstração)
    std::string gerarHash(const std::string& senha) const;
};
