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
    Usuario(string n, string e, string t);
    virtual ~Usuario() {}

    virtual void gerarRelatorio() const = 0; // Método virtual puro
};

#endif
