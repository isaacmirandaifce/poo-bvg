#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    Pessoa(); // Construtor padrão
    Pessoa(std::string nome, std::string telefone); // Construtor com parâmetros
    ~Pessoa(); // Destrutor

    void imprimirNome();
    void imprimirTelefone();
};

#endif
