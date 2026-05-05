#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    Usuario(std::string nome, std::string email, std::string tipo);
    virtual ~Usuario();

    // Método virtual puro para garantir abstração
    virtual void gerarRelatorio() = 0;
};

#endif
