#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() : nome(""), telefone("") {}

// Construtor parametrizado
Pessoa::Pessoa(const std::string& nome, const std::string& telefone) 
    : nome(nome), telefone(telefone) {}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Destruindo objeto: " << nome << std::endl;
}

// Método de impressão do nome
void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << nome << std::endl;
}

// Método de impressão do telefone
void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
