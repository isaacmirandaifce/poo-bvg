#include <iostream>
#include <string>
#include "contato.h" // Importação do header


// Construtor: garante que o valor recebido por parâmetro vá para o atributo privado da classe.
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destructor: é utilizado para liberar memoria quando um contato é deletado
Contato::~Contato() {
    std::cout << "LOG: Contato [" << this->nome << "] desalocado da memoria" << std::endl;
}


// Funções para imprimir nome e telefone
void Contato::imprimirNome() {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Contato::imprimirTelefone() {
    std::cout << "Telefone: " << this->telefone << std::endl;
}


