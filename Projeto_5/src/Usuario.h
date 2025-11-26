#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

using namespace std;

class Usuario {
protected:
    string nome;
    string email;
    string tipo;

public:
    Usuario();
    Usuario(const string &nome, const string &email, const string &tipo);
    virtual ~Usuario();

    // método abstrato puro: obrigará sobrescrita nas classes derivadas
    virtual void gerarRelatorio() const = 0;

    // getters básicos
    string getNome() const;
    string getEmail() const;
    string getTipo() const;
};

#endif // USUARIO_H