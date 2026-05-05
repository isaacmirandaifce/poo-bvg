#include "Pessoa.h"

using namespace std;

// Construtor padrão
Pessoa::Pessoa() {
    nome = "Indefinido";
    telefone = "0000-0000";
}

// Construtor parametrizado
// Uso do ponteiro 'this' para diferenciar atributo de parâmetro
Pessoa::Pessoa(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor
Pessoa::~Pessoa() {
    cout << "Objeto Pessoa (" << this->nome << ") foi destruido." << endl;
}

void Pessoa::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}

void Pessoa::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}
