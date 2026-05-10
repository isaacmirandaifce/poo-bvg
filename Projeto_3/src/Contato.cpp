#include "Contato.h"
#include <iostream>

namespace CRM {
    Contato::Contato(std::string nome, std::string telefone) {
        this->nome = nome;
        this->telefone = telefone;

    }

    Contato::~Contato(){
        std::cout << "Contato [ " << this->nome << "] removido da memoria" << std::endl;
    }

    void Contato::imprimirNome() const {
        std::cout << "Nome: " << this->nome << std::endl;
    } 

    void Contato::imprimirTelefone() const {
        std::cout << "Telefone: " << this->telefone << std::endl;
    } 
}