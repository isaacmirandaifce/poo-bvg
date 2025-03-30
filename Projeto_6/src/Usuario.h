#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nome;
    std::string email;

public:
    Usuario();
    Usuario(const std::string& nome, const std::string& email);
    virtual ~Usuario() = default;

    std::string getNome() const;
    std::string getEmail() const;

    virtual void exibirInformacoes() const = 0;
};

#endif