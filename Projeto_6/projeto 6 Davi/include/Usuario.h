
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nome;
    std::string login;

public:
    Usuario(std::string nome, std::string login);
    virtual ~Usuario() = default;
    std::string getNome() const;
    std::string getLogin() const;
};

#endif
