#include <iostream>
#include <string>
#include "contato.h"

Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

Contato::~Contato() {
    std::cout << "LOG: Contato [" << this->nome << "] desalocado da memoria" << std::endl;
}

void Contato::imprimirNome() {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Contato::imprimirTelefone() {
    std::cout << "Telefone: " << this->telefone << std::endl;
}


