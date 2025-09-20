#include "Pessoa.h"

// Para simplificar a escrita, usamos o namespace std, como sugerido
using namespace std;

// Implementação do construtor padrão
Pessoa::Pessoa() {
    this->nome = "Nao informado";
    this->telefone = "0000-0000";
}

// Implementação do construtor parametrizado
Pessoa::Pessoa(string nome, string telefone) {
    // Uso do ponteiro 'this' para diferenciar o atributo da classe do parâmetro do método
    this->nome = nome;
    this->telefone = telefone;
}

// Implementação do destrutor
Pessoa::~Pessoa() {
    // Exibe uma mensagem indicando qual objeto está sendo destruído
    cout << "Objeto Pessoa '" << this->nome << "' destruido." << endl;
}

// Implementação do método para imprimir o nome
void Pessoa::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}

// Implementação do método para imprimir o telefone
void Pessoa::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}
