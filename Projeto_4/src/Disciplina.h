#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>
using namespace std;

class Aluno; 

// Ele da aDeclaracao da função amiga que pode ser definida em Disciplina.cpp

bool verificarAprovacao(const Aluno &aluno, const class Disciplina &disc);

class Disciplina {

    private:
    string nome;
    int cargaHoraria;
    float nota;

public:
    
    Disciplina();
    Disciplina(const string &nome, int cargaHoraria);
    ~Disciplina();

    void setNota(float n);
    float getNota() const;
    string getNome() const;
    int getCargaHoraria() const;

    // função amiga, que declarada vai permitir acessar 'nota' diretamente
    
    friend bool verificarAprovacao(const Aluno &aluno, const Disciplina &disc);
};

#endif 