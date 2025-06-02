#include "Pessoa.h"

Pessoa::Pessoa() {
    this->nome = "Desconhecido";
    this->telefone = "0000-0000";
}


Pessoa::Pessoa(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}


Pessoa::~Pessoa() {
    cout << "Destruindo objeto da pessoa: " << this->nome << endl;
}


void Pessoa::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}


void Pessoa::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}
