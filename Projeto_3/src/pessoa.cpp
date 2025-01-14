#include "pessoa.h"

Pessoa::Pessoa() { // Construtor padrão
    nome = "";
    telefone = "";
    std::cout << "Pessoa criada com construtor padrão!" << std::endl;
}


Pessoa::Pessoa(const std::string& nome, const std::string& telefone) { // Construtor com parâmetros
    this->nome = nome;
    this->telefone = telefone;
    std::cout << "Pessoa criada com construtor parametrizado!" << std::endl;
}

Pessoa::~Pessoa() {// Destrutor
    std::cout << "Pessoa destruída!" << std::endl;
}

void Pessoa::imprimirNome() const {    // Imprimir o nome
    std::cout << "Nome: " << nome << std::endl;
}

void Pessoa::imprimirTelefone() const {     // Imprimir o telefone
    std::cout << "Telefone: " << telefone << std::endl;
}
