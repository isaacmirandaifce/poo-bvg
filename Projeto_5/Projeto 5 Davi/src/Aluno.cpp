#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno() {}

Aluno::Aluno(string nome, string email, string curso, int matricula)
    : Usuario(nome, email), curso(curso), matricula(matricula) {}

string Aluno::getCurso() const {
    return curso;
}

int Aluno::getMatricula() const {
    return matricula;
}

void Aluno::gerarRelatorio() const {
    cout << "Aluno: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Curso: " << curso << endl;
    cout << "Matrícula: " << matricula << endl;
}
