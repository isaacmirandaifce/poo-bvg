#include "Pessoa.h"

Pessoa::Pessoa() : nome("Indefinido"), telefone("Indefinido") {}

Pessoa::Pessoa(const std::string& nome, const std::string& telefone) : nome(nome), telefone(telefone) {}

Pessoa::~Pessoa() {
    std::cout << "Destruindo objeto Pessoa: " << nome << std::endl;
}

void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << nome << std::endl;
}

void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << telefone << std::endl;
}
