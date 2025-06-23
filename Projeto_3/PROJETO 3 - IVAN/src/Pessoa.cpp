#include "Pessoa.h"

Pessoa::Pessoa() {
    nome = "Desconhecido";
    telefone = "Sem número";
}

Pessoa::Pessoa(std::string nome, std::string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

Pessoa::~Pessoa() {
    std::cout << "Destruindo objeto Pessoa: " << nome << std::endl;
}

void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}

void Pessoa::imprimirDados() const {
    imprimirNome();
    imprimirTelefone();
    std::cout << "-----------------------------" << std::endl;
}
