#include "Contato.h"
#include <iostream>

// Construtor usando o ponteiro this para diferenciar variaveis
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor que emite o log quando o objeto sai de escopo
Contato::~Contato() {
    std::cout << "LOG: Contato " << this->nome << " desalocado da memoria.\n";
}

// Metodo para imprimir o nome
void Contato::imprimirNome() {
    std::cout << "Nome: " << this->nome << "\n";
}

// Metodo para imprimir o telefone
void Contato::imprimirTelefone() {
    std::cout << "Telefone: " << this->telefone << "\n";
}
