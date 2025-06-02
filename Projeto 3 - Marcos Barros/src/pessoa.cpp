#include "Pessoa.h"

//Construtor padrão
Pessoa::Pessoa() {
    this->nome = "Sem nome";
    this->telefone = "Sem telefone";
    cout << "Construtor padrão chamado para: " << this->nome << endl;
}

// Construtor parametrizado
Pessoa::Pessoa(const string& nome, const string& telefone) {
    this->nome = nome;
    this->telefone = telefone;
    cout << "Construtor parametrizado chamado para: " << this->nome << endl;
}

// Destrutor
Pessoa::~Pessoa() {
    cout << "Destrutor chamado para: " << this->nome << endl;
}

// Métodos de impressão
void Pessoa::imprimirNome() const {
    cout << "Nome: " << this->nome << endl;
}

void Pessoa::imprimirTelefone() const {
    cout << "Telefone: " << this->telefone << endl;
}
