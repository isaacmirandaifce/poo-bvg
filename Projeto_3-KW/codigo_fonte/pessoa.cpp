#include "pessoa.h"
#include <iostream>
using namespace std;
    Pessoa::Pessoa(){
        this->nome = "Desconhecido";
        this->telefone = "Sem telefone";
        
    }
    Pessoa::Pessoa(const string& nome,const string& telefone){
        this->nome = nome;
        this->telefone = telefone;
        
    }
    Pessoa::~Pessoa(){
        cout << "Sendo Destroçado";
    }
    void Pessoa::imprimirNome() const{
        cout << "Nome: "<< this->nome << "\n";
    }
    void Pessoa::imprimirTelefone() const{
        cout << "Telefone: " << this->telefone << "\n";
    }