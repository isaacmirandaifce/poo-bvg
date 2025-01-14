#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    Pessoa(); // Construtor

    
    Pessoa(const std::string& nome, const std::string& telefone);

    ~Pessoa();    // Destrutor

    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif
