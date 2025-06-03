#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() {
    this->nome = "Sem nome";
    this->telefone = "Sem telefone";
}

// Construtor parametrizado
Pessoa::Pessoa(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Destruindo objeto: " << this->nome << std::endl;
}

// Métodos
void Pessoa::imprimirNome() {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Pessoa::imprimirTelefone() {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
