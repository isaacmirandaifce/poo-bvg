#include "Pessoa.h"
#include <iostream>

using namespace std;

// Construtor informando quando a pessoa esta sendo criaada
Pessoa::Pessoa(const std::string& nome, const std::string& telefone)
    : nome(nome), telefone(telefone) {
    cout << "Pessoa criada: " << this->nome << ", Telefone: " << this->telefone << endl;
}

// Destrutor informando mensagens de limpeza
Pessoa::~Pessoa() {
    cout << "Destrutor chamado. Limpando recursos da pessoa: " << this->nome << endl;
}

// Getters
string Pessoa::getNome() const {
    return this->nome;
}

string Pessoa::getTelefone() const {
    return this->telefone;
}

// Métodos
void Pessoa::imprimirNome() const {
    cout << "Nome: " << this->nome << endl;
}

void Pessoa::imprimirTelefone() const {
    cout << "Telefone: " << this->telefone << endl;
}
