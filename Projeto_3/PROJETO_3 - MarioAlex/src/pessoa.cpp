#include "Pessoa.h"
#include <iostream>

using namespace std;

// Construtor padrão
Pessoa::Pessoa() {
    this->nome = "Desconhecido";
    this->telefone = "Sem número";
}

// Construtor com parâmetros
Pessoa::Pessoa(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor
Pessoa::~Pessoa() {
    cout << "Destrutor chamado para: " << this->nome << endl;
}

// Imprime o nome
void Pessoa::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}

// Imprime o telefone
void Pessoa::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}
