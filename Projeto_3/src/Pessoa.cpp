#include "Pessoa.h"
#include <iostream>

namespace app {

Pessoa::Pessoa()
    : nome("undefined"), telefone("undefined") {
    std::cout << "Objeto criado" << std::endl;
}

Pessoa::Pessoa(const std::string &nome, const std::string &telefone)
    : nome(nome), telefone(telefone) {
    std::cout << "Objeto criado" << std::endl;
}

Pessoa::~Pessoa() {
    std::cout << "Objeto pessoa destruído: " << nome << std::endl;
}

void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << nome << std::endl;
}

void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << telefone << std::endl;
}

}