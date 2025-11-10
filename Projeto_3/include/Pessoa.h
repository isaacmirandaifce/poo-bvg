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
        // Construtor padrão
        Pessoa();

        // Construtor parametrizado
        Pessoa(string nome, string telefone);

        // Destrutor
        ~Pessoa();

        // Métodos
        void imprimirNome();
        void imprimirTelefone();
};

#endif // PESSOA_H