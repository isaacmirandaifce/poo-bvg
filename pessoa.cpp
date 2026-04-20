#include "Pessoa.h"

// construtor padrão
Pessoa::Pessoa() {
    this->nome = "";
    this->telefone = "";
}

// construtor com parâmetros
Pessoa::Pessoa(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// destrutor
Pessoa::~Pessoa() {
    cout << "Objeto Pessoa destruido" << endl;
}

// imprime o nome
void Pessoa::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}

// imprime o telefone
void Pessoa::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}
