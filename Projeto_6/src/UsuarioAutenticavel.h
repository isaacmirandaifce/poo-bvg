#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"
#include <string>

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(std::string nome, std::string cpf, TipoUsuario tipo, std::string senha);
    virtual ~UsuarioAutenticavel();

 
    virtual bool autenticar(const std::string& senhaFornecida) const = 0;
};

#endif 