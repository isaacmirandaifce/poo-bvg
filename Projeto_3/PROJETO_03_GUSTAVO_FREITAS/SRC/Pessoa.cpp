#include "Pessoa.h"

Pessoa::Pessoa() : nome(""), telefone("") {}

Pessoa::Pessoa(std::string nome, std::string telefone) 
    : nome(nome), telefone(telefone) {}

Pessoa::~Pessoa() {
    std::cout << "Destruindo: " << nome << std::endl;
}

void Pessoa::imprimirNome() {
    std::cout << "Nome: " << nome << std::endl;
}

void Pessoa::imprimirTelefone() {
    std::cout << "Telefone: " << telefone << std::endl;
}

void Pessoa::setNome(std::string nome) {
    this->nome = nome;
}

void Pessoa::setTelefone(std::string telefone) {
    this->telefone = telefone;
}

std::string Pessoa::getNome() const {
    return nome;
}

std::string Pessoa::getTelefone() const {
    return telefone;
}