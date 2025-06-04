#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

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