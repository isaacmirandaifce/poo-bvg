#include "Aluno.h"
#include <iostream>

using namespace std;

Aluno::Aluno() {}

Aluno::Aluno(string nome, string email, string matricula, string curso)
: Usuario(nome, email, "Aluno"){
    this->matricula = matricula;
    this->curso = curso;
}

void Aluno::adicionarDisciplina(string disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    cout << "Aluno: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
}

void Aluno::exibirDetalhes() const {
    cout << "Aluno " << nome << " | Curso: " << curso << endl;
}

void Aluno::exibirDetalhes(bool mostrarNotas) const {
    cout << "Aluno: " << nome << endl;
    if (mostrarNotas) {
        cout << "Notas: [Exemplo]" << endl;
    }
}
