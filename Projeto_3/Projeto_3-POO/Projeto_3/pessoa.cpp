#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() : nome(""), telefone("") {}

// Construtor parametrizado
Pessoa::Pessoa(std::string nome, std::string telefone) : nome(nome), telefone(telefone) {}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Pessoa " << nome << " destruída." << std::endl;
}

// Métodos para imprimir nome e telefone
void Pessoa::imprimirNome() {
    std::cout << "Nome: " << nome << std::endl;
}

void Pessoa::imprimirTelefone() {
    std::cout << "Telefone: " << telefone << std::endl;
}
