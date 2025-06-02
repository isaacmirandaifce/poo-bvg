#include "Pessoa.h"

Pessoa::Pessoa() {
    this->nome = "Desconhecido";
    this->telefone = "Sem telefone";
}

Pessoa::Pessoa(const std::string& nome, const std::string& telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

Pessoa::~Pessoa() {
    std::cout << "Destruindo objeto Pessoa: " << this->nome << std::endl;
}

void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
