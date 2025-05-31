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
    Pessoa(); //Construtor padrão
    Pessoa(string nome, string telefone); //Construtor parametrizado
    ~Pessoa(); //Destrutor

    void imprimirDados();
};

#endif // PESSOA_H
