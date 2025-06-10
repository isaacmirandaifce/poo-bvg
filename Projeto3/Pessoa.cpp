#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() : nome(""), telefone("") {}

// Construtor parametrizado
Pessoa::Pessoa(const std::string& nome, const std::string& telefone) {
    // Usando ponteiro this para boas práticas
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Objeto Pessoa com nome \"" << this->nome << "\" está sendo destruído." << std::endl;
}

// Imprime o nome da pessoa
void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

// Imprime o telefone da pessoa
void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
