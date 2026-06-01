#include "Contato.h"
#include <iostream>

// Construtor utilizando o ponteiro 'this'
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor com log de sistema
Contato::~Contato() {
    std::cout << "LOG: Contato [" << this->nome << "] desalocado da memoria.\n";
}

// Implementação dos métodos
void Contato::imprimirNome() {
    std::cout << "Nome: " << this->nome << "\n";
}

void Contato::imprimirTelefone() {
    std::cout << "Telefone: " << this->telefone << "\n";
}