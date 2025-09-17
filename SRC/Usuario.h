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
    Usuario(const std::string& nome, const std::string& email, const std::string& tipo);
    virtual ~Usuario() {}

    // Método virtual puro
    virtual void exibirInformacoes() const = 0;

    // Getters
    std::string getNome() const;
    std::string getEmail() const;
    std::string getTipo() const;
};

#endif // USUARIO_H