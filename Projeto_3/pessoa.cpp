#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() : nome(""), telefone("") {
    std::cout << "Objeto Pessoa criado (padrão)." << std::endl;
}

// Construtor parametrizado
Pessoa::Pessoa(const std::string& nome, const std::string& telefone) 
    : nome(nome), telefone(telefone) {
    std::cout << "Objeto Pessoa criado (parametrizado)." << std::endl;
}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Objeto Pessoa destruído: " << this->nome << std::endl;
}

// Métodos para imprimir
void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}

// Métodos de acesso
const std::string& Pessoa::getNome() const {
    return this->nome;
}

const std::string& Pessoa::getTelefone() const {
    return this->telefone;
}
