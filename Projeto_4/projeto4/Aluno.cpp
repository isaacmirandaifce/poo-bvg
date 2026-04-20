#include "Aluno.h"
#include <iostream>

using namespace std;

Aluno::Aluno() {
    nome = "";
    matricula = "";
    curso = "";
}

Aluno::Aluno(string nome, string matricula, string curso) {
    this->nome = nome;
    this->matricula = matricula;
    this->curso = curso;
}

void Aluno::exibirInformacoes() {
    cout << "--- Informacoes do Aluno ---" << endl;
    cout << "Nome: " << this->nome << endl;
    cout << "Matricula: " << this->matricula << endl;
    cout << "Curso: " << this->curso << endl;
    cout << "----------------------------" << endl;
}
