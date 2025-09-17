#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nome;
    string email;
    string tipo;

public:
    Usuario();
    Usuario(string nome, string email, string tipo);
    virtual ~Usuario();

    string getNome() const;
    string getEmail() const;
    string getTipo() const;
};

#endif