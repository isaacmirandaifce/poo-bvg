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
    Pessoa(); // construtor padrão
    Pessoa(string nome, string telefone); // construtor parametrizado
    ~Pessoa(); // destrutor

    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif // PESSOA_H