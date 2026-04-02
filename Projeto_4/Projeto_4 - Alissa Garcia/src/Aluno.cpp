//Código de Alissa Garcia ADS S3

#include "Aluno.h"


//Implementação da Classe

// Construtor padrão
    Aluno::Aluno(){
        this->nome      = "NULL";
        this->matricula = "NULL";
        this->curso     = "NULL";

        //Deixei tudo nulo por default
    }

// Construtor parametrizado
    Aluno::Aluno(string nome, string matricula, string curso){
        this->nome      = nome;
        this->matricula = matricula;
        this->curso     = curso;
    }

// Destrutor
    Aluno::~Aluno(){
        std::cout << "O(a) Aluno(a) " << this->nome << " está sendo destruido(a)!" << endl;
    }
    // Implementação do destrutor para exibir mensagens de limpeza.

// Metodo de impressao das informações:
    void Aluno::exibirInformacoes(){
        std::cout << "O nome da Aluno é: " << this->nome << endl;
        std::cout << "A matrícula é: " << this->matricula << endl;
        std::cout << "O Curso é " << this->curso << endl << endl;
        //Utilizando std::cout saída de dados
    }

