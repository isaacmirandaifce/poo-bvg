#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    // Construtor padrão
    Pessoa();

    // Construtor parametrizado
    Pessoa(std::string nome, std::string telefone);

    // Destrutor
    ~Pessoa();

    // Métodos de impressão
    void imprimirNome();
    void imprimirTelefone();
};

#endif // PESSOA_H
