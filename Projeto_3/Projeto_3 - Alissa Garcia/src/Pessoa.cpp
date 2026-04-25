//Código de Alissa Garcia ADS S3

//Implementação da Classe

#include "Pessoa.h"

// Construtor padrão
    Pessoa::Pessoa(){
        this->nome     = "NULL";
        this->telefone = "NULL";
        //Deixei tudo nulo por default
    }

// Construtor parametrizado
    Pessoa::Pessoa(string nome, string telefone){
        this->nome     = nome;
        this->telefone = telefone;
    }

// Destrutor
    Pessoa::~Pessoa(){
        std::cout << "A pessoa " << this->nome << " está sendo destruida!" << endl;
    }
    //- Implementação do destrutor para exibir mensagens de limpeza.

// Metodo de impressao do nome
    void Pessoa::imprimirNome(){
        std::cout << "O nome da Pessoa é: " << this->nome << endl;
        //Utilizando std::cout saída de dados
    }

// Metodo de impressao do nome
 void Pessoa::imprimirTelefone(){
        std::cout << "O telefone da " << this->nome << " é "<< this->telefone << endl;
    }