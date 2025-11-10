#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa() {
    this->nome = "Sem nome";
    this->telefone = "Sem telefone";
    cout << "Objeto Pessoa criado (contrutor padrão)." << endl;
}

// Construtor parametrizado
Pessoa::Pessoa(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
    cout << "Objeto Pessoa criado (contrutor parametrizado)" << endl;
}

// Destrutor
Pessoa::~Pessoa() {
    cout << "Objeto Pessoa destruído: " << this->nome << endl;
}

// Método de impressão do nome
void Pessoa::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}

// Método de impressão do telefone
void Pessoa::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}