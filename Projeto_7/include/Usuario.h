#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
using namespace std;

class Usuario {
protected:
    string nome, email;
public:
    Usuario(string n, string e) : nome(n), email(e) {}
    virtual void gerarRelatorio() const = 0;
    virtual ~Usuario() {}
};

#endif // USUARIO_H