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
    Pessoa(std::string nome, std::string telefone);
    ~Pessoa();
    
    void imprimirNome();
    void imprimirTelefone();
    
    void setNome(std::string nome);
    void setTelefone(std::string telefone);
    
    std::string getNome() const;
    std::string getTelefone() const;
};

#endif // PESSOA_H