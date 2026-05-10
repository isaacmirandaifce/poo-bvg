#include "Contato.h"

using namespace std;

// Construtor
Contato::Contato(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor
Contato::~Contato() {
    cout << "LOG: Contato [" << nome
         << "] desalocado da memoria." << endl;
}

// Método para imprimir nome
void Contato::imprimirNome() {
    cout << "Nome: " << nome << endl;
}

// Método para imprimir telefone
void Contato::imprimirTelefone() {
    cout << "Telefone: " << telefone << endl;
}