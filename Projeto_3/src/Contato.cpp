#include "Contato.h"

// Construtor padrão
Contato::Contato() : nome(""), telefone("") {}

// Construtor parametrizado utilizando obrigatoriamente o ponteiro 'this'
Contato::Contato(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor que emite log ao desalocar memória
Contato::~Contato() {
    std::cout << "[LOG]: Contato \"" << this->nome << "\" desalocado da memoria." << std::endl;
}

// Método de impressão do nome
void Contato::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

// Método de impressão do telefone
void Contato::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}