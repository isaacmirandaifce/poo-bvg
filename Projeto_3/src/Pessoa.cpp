#include "Pessoa.h"

// construtor padrão
Pessoa::Pessoa() {
    this->nome = "Desconhecido";
    this->telefone = "Sem telefone";
}

// construtor parametrizado
Pessoa::Pessoa(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// destrutor
Pessoa::~Pessoa() {
    cout << "Destruindo objeto da pessoa: " << this->nome << endl;
}

// imprimir nome
void Pessoa::imprimirNome() const {
    cout << "Nome: " << this->nome << endl;
}

// imprimir telefone
void Pessoa::imprimirTelefone() const {
    cout << "Telefone: " << this->telefone << endl;
}
