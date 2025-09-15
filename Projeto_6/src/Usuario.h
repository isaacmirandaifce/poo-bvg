#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h"

class Usuario {
protected:
    std::string nome;
    std::string email;
    int id;
    TipoUsuario tipo;

public:
    Usuario(const std::string& nome, const std::string& email, int id, TipoUsuario tipo);
    virtual ~Usuario() = default;

    // Getters
    std::string getNome() const;
    std::string getEmail() const;
    int getId() const;
    TipoUsuario getTipo() const;

    // Setters
    void setNome(const std::string& nome);
    void setEmail(const std::string& email);

    virtual void exibirInformacoes() const;
};

#endif
