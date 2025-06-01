#include "Pessoa.h" // Inclui o cabeçalho com a definição da classe


Pessoa::Pessoa() {
    this->nome = "Desconhecido";
    this->telefone = "Sem telefone";
}

// Construtor parametrizado
Pessoa::Pessoa(string nome, string telefone) {
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor
Pessoa::~Pessoa() {
    cout << "Destruindo objeto Pessoa: " << this->nome << endl;
}

//imprimir o nome da pessoa
void Pessoa::imprimirNome() {
    cout << "Nome: " << this->nome << endl;
}

//imprimir o telefone da pessoa
void Pessoa::imprimirTelefone() {
    cout << "Telefone: " << this->telefone << endl;
}
