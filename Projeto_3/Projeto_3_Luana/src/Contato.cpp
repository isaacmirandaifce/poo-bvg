#include "Contato.h"
#include <iostream>

Contato::Contato(std::string nome, std::string telefone){
    this->nome = nome;
    this->telefone = telefone;
}

Contato::~Contato(){
    std::cout << "LOG: Registro do contato " << nome << " liberado." << std::endl;
}

void Contato::imprimirNome() {
    std::cout << "Nome: " << nome << std::endl;
}

void Contato::imprimirTelefone() {
    std::cout << "Telefone: " << telefone << std::endl;
}
 