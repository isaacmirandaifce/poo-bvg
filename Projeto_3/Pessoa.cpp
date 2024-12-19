#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() : nome(""), telefone("") {
    std::cout << "Construtor padrão chamado.\n";
}

// Construtor parametrizado
Pessoa::Pessoa(const std::string& nome, const std::string& telefone) : nome(nome), telefone(telefone) {
    std::cout << "Construtor parametrizado chamado para " << nome << ".\n";
}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Destrutor chamado para " << nome << ".\n";
}

// Método para imprimir o nome
void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << "\n";
}

// Método para imprimir o telefone
void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << "\n";
}
