#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() : nome("Indefinido"), telefone("Indefinido") {
    std::cout << "Objeto Pessoa criado (padrão)" << std::endl;
}

// Construtor parametrizado
Pessoa::Pessoa(const std::string &nome, const std::string &telefone) 
    : nome(nome), telefone(telefone) {
    std::cout << "Objeto Pessoa criado com dados fornecidos" << std::endl;
}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Objeto Pessoa destruido: " << this->nome << std::endl;
}

// Métodos de impressão
void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
