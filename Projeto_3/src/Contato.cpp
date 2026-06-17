#include "Contato.h"

using namespace std;

// Construtor padrao
Contato::Contato() {
    this->nome = "";
    this->telefone = "";
}

// Construtor parametrizado: usa o ponteiro "this" para diferenciar
// os atributos da classe dos parametros recebidos, que possuem o mesmo nome.
Contato::Contato(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor: emite um log informando que o contato foi desalocado da memoria
Contato::~Contato() {
    cout << "LOG: Contato " << this->nome << " desalocado da memoria." << endl;
}

void Contato::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}

void Contato::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}
