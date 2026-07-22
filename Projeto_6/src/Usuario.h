#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h"

// Classe base comum a todos os usuarios do sistema academico.
class Usuario {
protected:
    std::string nome;
    std::string email;
    TipoUsuario tipo;

public:
    Usuario();
    Usuario(std::string nome, std::string email, TipoUsuario tipo);
    virtual ~Usuario();

    std::string getNome() const;
    std::string getEmail() const;
    TipoUsuario getTipo() const;
};

#endif // USUARIO_H
