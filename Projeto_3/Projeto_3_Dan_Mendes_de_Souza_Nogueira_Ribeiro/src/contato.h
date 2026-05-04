#pragma once
#include <iostream>
#include <string>

class Contato {
    private:

    std::string nome;
    std::string telefone;

    public:

    std::string getNome() {};

    std::string getTelefone() {};

    void setTelefone(){};

    void setNome(){};

    Contato(){};

    ~Contato(){};


    //////

    void imprimirNome(){};

    void imprimirTelefone(){};
};