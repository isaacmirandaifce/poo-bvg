#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>
using namespace std;

class Disciplina; 

class Aluno {
private:
    string nome;
    string matricula;
    string curso;

public:
    
// Construtores
    
Aluno();
Aluno(const string &nome, const string &matricula, const string &curso);
~Aluno();

// Métodos

void exibirInformacoes() const;

// Getters 

string getNome() const;
string getMatricula() const;
string getCurso() const;
};

#endif