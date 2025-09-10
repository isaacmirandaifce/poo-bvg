#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    usuario();
    usuario(std::string nome, std::string email, std::string tipo);
    virtual ~usuario();

    virtual void gerarRelatorio() const = 0;
};

#endif