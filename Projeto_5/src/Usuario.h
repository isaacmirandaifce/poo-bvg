#ifndef USUARIO_H
#define USUARIO_H

#include <string>

// classe base abstrata
class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    Usuario(); // construtor padrão
    Usuario(std::string nome, std::string email, std::string tipo); // construtor parametrizado
    virtual ~Usuario() {}

    // método virtual puro para gerar relatório (sobrescrito nas classes derivadas)
    virtual void gerarRelatorio() const = 0;
};

#endif
