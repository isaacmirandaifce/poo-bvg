#include "Contato.h"
#include <iostream>

// Construtor utilizando this-> para resolver ambiguidade
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor emitindo log no console
Contato::~Contato() {
    std::cout << "LOG: Contato [" << this->nome << "] desalocado da memoria." << std::endl;
}

// Métodos de impressão
void Contato::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Contato::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}