#ifndef CONTATO_H
#define CONTATO_H

#include <string>
#include <iostream>

class Contato {
private:
    std::string nome;
    std::string telefone;

public:
    // Construtor padrao
    Contato();

    // Construtor parametrizado
    Contato(std::string nome, std::string telefone);

    // Destrutor
    ~Contato();

    void imprimirNome();
    void imprimirTelefone();
};

#endif // CONTATO_H
