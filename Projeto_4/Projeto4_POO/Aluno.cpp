#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno() {}

Aluno::Aluno(string n, string m, string c) {
    nome = n;
    matricula = m;
    curso = c;
}

void Aluno::exibirInformacoes() {
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
}
