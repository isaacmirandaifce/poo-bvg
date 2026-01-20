#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(const std::string& nome, const std::string& email,
                       const std::string& matricula, TipoUsuario tipo,
                       const std::string& senha);
    
    virtual bool autenticar(const std::string& senha) const;
    void setSenha(const std::string& novaSenha);
};

#endif // USUARIO_AUTENTICAVEL_H