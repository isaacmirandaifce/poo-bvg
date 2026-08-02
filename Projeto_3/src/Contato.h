#ifndef CONTATO_H
#define CONTATO_H

#include <string>
#include <iostream>

class Contato {
private:
    std::string nome;
    std::string telefone;

public:
    Contato();
    Contato(std::string nome, std::string telefone); 
    ~Contato(); 
    void imprimirNome();
    void imprimirTelefone();
};

#endif // CONTATO_H