#include "Pessoa.h"

// Construtor padrão
Pessoa::Pessoa(){
    this->nome="";
    this->telefone="";
}
// Construtor parametrizado
Pessoa::Pessoa(string nome, string telefone){
    this->nome=nome;
    this->telefone=telefone;
}
// Destrutor
Pessoa::~Pessoa(){
    cout << "Objeto destruído" << endl;
}
// Metodo de impressao do nome
void Pessoa::imprimirNome(){
    cout << "Nome: " << this->nome << endl;
}

// Metodo de impressao do telefone
void Pessoa::imprimirTelefone(){
    cout << "Telefone: " << this->telefone << endl;
}
