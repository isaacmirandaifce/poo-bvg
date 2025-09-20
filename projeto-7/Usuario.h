#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h"

class Usuario {
protected:
    std::string nome;
    std::string email;
    TipoUsuario tipo;

public:
    // Construtor para inicializar os atributos
    Usuario(std::string nome, std::string email, TipoUsuario tipo);

    // Destrutor virtual
    virtual ~Usuario() {}

    const std::string& getNome() const;
};

#endif // USUARIO_H
