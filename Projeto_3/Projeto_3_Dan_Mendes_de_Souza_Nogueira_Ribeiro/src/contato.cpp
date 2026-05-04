#include <iostream>
#include <string>
#include "contato.h"


    std::string Contato::getNome() {

        return this->nome;
    };

    std::string Contato::getTelefone(){
        
        return this->telefone;
    };

    void Contato::setTelefone(std::string telefone){

        this->telefone = telefone;
    };

    void Contato::setNome(std::string nome) {

        this->nome = nome;
    };

    Contato::Contato(){
        std::cout << "Contato criado." << '\n';
    };

    Contato::~Contato(){


        std::string nome = getNome();

        std::cout << "O Contato de nome: " << nome << ". Foi apagado com sucesso." << '\n';
    };

    void Contato::imprimirNome()
    {

        std::string nome = getNome();

        std::cout << "O nome deste contato é : " << nome << '\n';
    };

    void Contato::imprimirTelefone() {

        std::string telefone = getTelefone();

        std::cout << "O numero deste contato é : " << telefone << '\n';
    };