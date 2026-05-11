#include <iostream>
#include <string>
#pragma once

class Contato {
    private:

    std::string nome;
    std::string telefone;

    public:

    void setTelefone(std::string telefone);

    void setNome(std::string nome);

    Contato();

    ~Contato();


    //////

    void imprimirNome();

    void imprimirTelefone();
};

Contato AdicionarContatos(std::string nome, std::string telefone);