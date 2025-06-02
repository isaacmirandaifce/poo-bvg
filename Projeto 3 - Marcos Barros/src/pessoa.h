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
    Pessoa(const string& nome, const string& telefone); //Construtor parametrizado
    ~Pessoa(); //Destrutor

    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif 
