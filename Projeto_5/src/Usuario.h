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
    virtual ~Usuario();

    // Metodo virtual puro: cada tipo de usuario define seu proprio relatorio
    virtual void gerarRelatorio() const = 0;

    std::string getNome() const;
};

#endif // USUARIO_H
