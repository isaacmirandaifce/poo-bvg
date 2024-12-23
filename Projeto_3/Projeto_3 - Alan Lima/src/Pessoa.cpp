#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() : nome(""), telefone("") {}

// Construtor parametrizado
Pessoa::Pessoa(const std::string& nome, const std::string& telefone) {
    this->nome = nome;   
    this->telefone = telefone;
}

// Destrutor
Pessoa::~Pessoa() {}

void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;  // Usando 'this'
}

void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
