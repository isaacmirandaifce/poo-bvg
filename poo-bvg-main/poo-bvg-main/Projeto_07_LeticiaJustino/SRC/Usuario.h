#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h"

class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string matricula;
    TipoUsuario tipo;

public:
    Usuario(const std::string& nome, const std::string& email, 
            const std::string& matricula, TipoUsuario tipo);
    virtual ~Usuario() = default;

    std::string getNome() const;
    std::string getEmail() const;
    std::string getMatricula() const;
    TipoUsuario getTipo() const;

    void setNome(const std::string& nome);
    void setEmail(const std::string& email);
    void setMatricula(const std::string& matricula);
};

#endif // USUARIO_H