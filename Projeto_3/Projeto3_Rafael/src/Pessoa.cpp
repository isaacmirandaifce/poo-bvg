#include "Pessoa.h"

using namespace std;

// Construtor padrão
Pessoa::Pessoa(){
    this->nome = "";
    this->telefone = "";
}

// Construtor parametrizado
Pessoa::Pessoa(string nome, string telefone){
    this->nome = nome;
    this->telefone = telefone;
}

// Destrutor
Pessoa::~Pessoa(){
    cout << "Destruindo objeto da pessoa: " << this->nome << endl;
}

//metodo de impressão
void Pessoa::imprimirDados(){
    cout << "Nome: " << this->nome << endl << "Telefone: " << this->telefone << endl << endl;
}