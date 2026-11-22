#include "Contato.h"
#include <iostream>

// Construtor parametrizado: usa 'this' para diferenciar os parâmetros dos atributos da classe.
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor: log de sistema ao remover o contato da memória.
Contato::~Contato() {
    std::cout << "LOG: Contato [" << this->nome
              << "] desalocado da memória." << std::endl;
}

void Contato::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Contato::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}