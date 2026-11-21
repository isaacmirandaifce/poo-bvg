#include "Contato.h"
#include <iostream>

//Construtor parametrizado
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

//Destrutor
Contato::~Contato() {
    std::cout << "Sistema: encerrando e liberando contato " << this->nome << "!" << std::endl;
}

//Métodos de exibição
void Contato::imprimirNome() {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Contato::imprimirTelefone() {
    std::cout << "Telefone: " << this->telefone << std::endl;
}