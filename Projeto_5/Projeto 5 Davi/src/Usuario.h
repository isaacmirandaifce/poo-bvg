#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nome;
    string email;

public:
    Usuario();
    Usuario(string nome, string email);
    virtual ~Usuario() = default;

    virtual void gerarRelatorio() const = 0; // método abstrato puro
};

#endif
