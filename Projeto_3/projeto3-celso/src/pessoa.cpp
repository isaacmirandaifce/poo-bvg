#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() : nome(""), telefone("") {
    std::cout << "Construtor padrão chamado para objeto Pessoa\n";
}

// Construtor parametrizado
Pessoa::Pessoa(const std::string& nome, const std::string& telefone) : nome(nome), telefone(telefone) {
    std::cout << "Construtor parametrizado chamado para objeto Pessoa: " << this->nome << "\n";
}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Destrutor chamado para objeto Pessoa: " << this->nome << "\n";
}

// Imprime o nome da pessoa
void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

// Imprime o telefone da pessoa
void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
