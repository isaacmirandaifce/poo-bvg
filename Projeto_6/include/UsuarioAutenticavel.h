#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include "usuario.h"
#include <string>


// Classe base Usuario
class UsuarioAutenticavel : public Usuario {
private:
    std::string senha;
public:
    UsuarioAutenticavel();
    UsuarioAutenticavel(const std::string& nome, const std::string& email, TipoUsuario tipo, const std::string& senha);
    virtual bool autenticar(const std::string& senha) const = 0;
    virtual ~UsuarioAutenticavel();
    std::string getSenha() const;
};

#endif // USUARIOAUTENTICAVEL_H
