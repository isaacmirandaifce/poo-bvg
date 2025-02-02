#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nome;
    std::string email;

public:
    Usuario(std::string nome, std::string email) : nome(nome), email(email) {}
    virtual ~Usuario() = default;

    std::string getNome() const { return nome; }
    std::string getEmail() const { return email; }
};

#endif // USUARIO_H
