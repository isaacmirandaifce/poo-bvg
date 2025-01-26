#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "../usuario/Usuario.h"  // Corrigido caminho relativo

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& senha);
    virtual bool autenticar(const std::string& senhaTentativa) = 0;
};

#endif
