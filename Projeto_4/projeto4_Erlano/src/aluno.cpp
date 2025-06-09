#include "aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(string n, string m, string c) : nome(n), matricula(m), curso(c) {}

void Aluno::exibirInformacoes() const {
    cout << "Nome: " << nome << endl;
    cout << "Matrícula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
}