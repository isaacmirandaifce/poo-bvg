#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

/* Classe base Usuario */
class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    Usuario();
    Usuario(const std::string& nome, const std::string& email, const std::string& tipo);

    virtual void gerarRelatorio() const = 0; // Método virtual puro

    virtual ~Usuario(); // Declaração do destrutor virtual
};

#endif // USUARIO_H
