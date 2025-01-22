#include "../include/Pessoa.h"

Pessoa::Pessoa(std::string nome, std::string fone){
       this->nome = nome;
       this->telefone = fone;

}

Pessoa::~Pessoa(){ //destrutor
}

std::string Pessoa::getNome() const{  // retorna o nome
    return nome; 
}

std::string Pessoa::getTelefone() const{ // retorna o telefone
    return telefone;
}


void Pessoa::ImprimirNome(){
std::cout << "Nome: " << this->getNome() << std::endl; // imprime o nome usando o getNome para pegar o nome
}

void Pessoa::ImprimirTelefone(){
    std::cout << "Telefone: " << this->getTelefone() << std::endl; // imprime o telefone usando o getTelefone para pegar o telefone
}

void Pessoa::exibirInformacoes() const{  
std::cout << "Nome: " << nome << "  " << "Telefone: " << telefone << std::endl;
};
