#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    Usuario();
    Usuario(std::string nome, std::string email, std::string tipo);
    virtual ~Usuario() = default;

    virtual void gerarRelatorio() const = 0; // Método puro
};

#endif // USUARIO_H
