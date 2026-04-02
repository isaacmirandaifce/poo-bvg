//Código de Alissa Garcia ADS S3

#include "Disciplina.h"
#include <string>
#include <iostream>

using namespace std;


//Implementação da Classe

// Construtor padrão
    Disciplina::Disciplina(){
        this->nome         = "NULL";
        this->cargaHoraria = 0;
        this->nota         = 0;

        //Deixei tudo nulo por default
    }

// Construtor parametrizado
    Disciplina::Disciplina(string nome, int cargaHoraria, float nota){
        this->nome         = nome;
        this->cargaHoraria = cargaHoraria;
        this->nota         = nota;
    }

// Destrutor
    Disciplina::~Disciplina(){
        std::cout << "A Disciplina " << this->nome << " está sendo destruido(a)!" << endl;
    }
    // Implementação do destrutor para exibir mensagens de limpeza.

// Metodo de impressao das informações:
    float Disciplina::getNota(){

        return nota;

    }
    void Disciplina::setNota(float nota){
        
        this->nota = nota;

    }


