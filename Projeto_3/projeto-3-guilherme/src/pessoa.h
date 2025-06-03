#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    Pessoa(); // Construtor padrão
    Pessoa(std::string nome, std::string telefone); // Construtor parametrizado
    ~Pessoa(); // Destrutor

    void imprimirNome();
    void imprimirTelefone();
};

#endif // PESSOA_H
