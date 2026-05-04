#pragma once
#include <iostream>
#include <string>

class Contato {
    private:

    std::string nome;
    std::string telefone;

    public:

    std::string getNome(){};

    std::string getTelefone(){};

    void setTelefone(std::string telefone){};

    void setNome(std::string nome) {};

    Contato(){};

    ~Contato(){};


    //////

    void imprimirNome(){};

    void imprimirTelefone(){};
};