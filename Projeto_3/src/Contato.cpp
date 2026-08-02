#include "Contato.h"
using namespace std;

Contato::Contato() {
    this->nome = "Desconhecido";
    this->telefone = "Não informado";
}
Contato::Contato(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}
Contato::~Contato() {
    cout << "LOG: Contato [" << this->nome << "] desalocado da memoria." << endl;
}

void Contato::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}

void Contato::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}