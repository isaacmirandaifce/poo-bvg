/**
 * @file Contato.cpp
 * @brief Implementação dos métodos da classe Contato.
 */

#include "Contato.h"
#include <iostream>

// Construtor: os parâmetros têm o MESMO nome dos atributos.
// O ponteiro "this" aponta para o objeto atual, então:
//   this->nome  -> atributo da classe
//   nome        -> parâmetro recebido
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor: emite um log quando o objeto é destruído.
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
