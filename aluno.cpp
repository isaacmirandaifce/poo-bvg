#include "Aluno.h"
#include <iostream>

using namespace std;

Aluno::Aluno() {}

Aluno::Aluno(string nome, string email, string matricula, string curso)
    : Usuario(nome, email, "Aluno") {
    this->matricula = matricula;
    this->curso = curso;
}

void Aluno::adicionarDisciplina(string d) {
    disciplinas.push_back(d);
}

void Aluno::gerarRelatorio() {
    cout << "Aluno: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
}

void Aluno::exibirDetalhes() {
    cout << "Aluno sem notas" << endl;
}

void Aluno::exibirDetalhes(bool comNotas) {
    if (comNotas)
        cout << "Aluno com notas" << endl;
}
