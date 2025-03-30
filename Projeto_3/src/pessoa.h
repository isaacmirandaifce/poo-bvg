#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    Pessoa();
    Pessoa(const std::string& nome, const std::string& telefone);
    ~Pessoa();

    void imprimirNome() const;
    void imprimirTelefone() const;
};