#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    string telefone;

public:
    Pessoa();
    Pessoa(string nome, string telefone);
    ~Pessoa();

    void imprimirNome();
    void imprimirTelefone();
};

#endif
