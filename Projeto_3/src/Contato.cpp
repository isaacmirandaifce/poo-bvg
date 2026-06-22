#include "Contato.h"

// Construtor
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
    std::cout << "LOG: Contato [" << this->nome << "] criado na memória." << std::endl;
}

// Destrutor
Contato::~Contato() {
    std::cout << "LOG: Contato [" << this->nome << "] desalocado da memória." << std::endl;
}

// Método para Imprimir nome
void Contato::imprimirNome() const { 
    std::cout << "Nome: " << this->nome << std::endl;
}

// Método para imprimir telefone
void Contato::imprimirTelefone() const { 
    std::cout << "Telefone: " << this->telefone << std::endl;
}