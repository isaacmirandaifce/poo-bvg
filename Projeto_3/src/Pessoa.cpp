#include "Pessoa.h"
#include <iostream>

using namespace std;

// Implementações dos métodos da classe Pessoa

// Construtor padrão
// Inicializa os atributos nome e telefone com strings vazias.
Pessoa::Pessoa() : nome(""), telefone("") {}

// Construtor parametrizado
// Recebe os valores de nome e telefone por valor e os atribui aos atributos
// do objeto. Aqui usamos `this->` para deixar explícito que estamos
// acessando os membros da instância atual;
Pessoa::Pessoa(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor
// É chamado quando um objeto Pessoa sai de escopo ou é destruído.
Pessoa::~Pessoa() {
    cout << "Destruindo objeto Pessoa: " << this->nome << endl;
}

// Método que imprime o nome da pessoa.
void Pessoa::imprimirNome() const {
    cout << "Nome: " << this->nome << endl;
}

// Método que imprime o telefone da pessoa.
void Pessoa::imprimirTelefone() const {
    cout << "Telefone: " << this->telefone << endl;
}