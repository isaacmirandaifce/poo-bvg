#ifndef CONTATO_H
#define CONTATO_H

#include <iostream>
#include <string>

class Contato {
private:
    std::string nome;
    std::string telefone;

public:
    // Construtor
    Contato(std::string nome, std::string telefone);

    // Destrutor
    ~Contato();

    // Métodos
    void imprimirNome();
    void imprimirTelefone();
};

#endif