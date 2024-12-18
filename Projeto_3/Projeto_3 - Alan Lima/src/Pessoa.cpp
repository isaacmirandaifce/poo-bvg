#include "Pessoa.h"

// Construtor com valor padrão
Pessoa::Pessoa() : nome("desconhecido"), telefone("não informado") {}

// Construtor parametrizado
Pessoa::Pessoa(const std::string& nome, const std::string& telefone) {
    this->nome = nome;       // Usando o ponteiro 'this'
    this->telefone = telefone;
}

// Destrutor
Pessoa::~Pessoa() {}

// Método para imprimir o nome
void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;  // Usando 'this'
}

// Método para imprimir o telefone
void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
