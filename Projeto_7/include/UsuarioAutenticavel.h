#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include "TipoUsuario.h"  
#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;
    TipoUsuario tipo;  
public:
    UsuarioAutenticavel(std::string n, std::string e, std::string s, TipoUsuario t); 

    virtual bool autenticar(std::string s) const = 0;
};


#endif // USUARIOAUTENTICAVEL_H
