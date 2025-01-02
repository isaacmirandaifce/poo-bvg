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
    Pessoa(const std::string& nome, const std::string& telefone); // Construtor parametrizado
    ~Pessoa(); // Destrutor

    void imprimirNome() const; // Método para imprimir o nome
    void imprimirTelefone() const; // Método para imprimir o telefone
};

#endif
