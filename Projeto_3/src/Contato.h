#ifndef CONTATO_H
#define CONTATO_H

#include <string>

//Declaração da classe Contato
class Contato {
private:
    std::string nome;
    std::string telefone;

public:
    //Construtor parametrizado
    Contato(std::string nome, std::string telefone);

    //Destrutor
    ~Contato();

    //Métodos de exibição
    void imprimirNome();
    void imprimirTelefone();
};

#endif