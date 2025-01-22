#include "Aluno.h"
#include <iostream>

namespace std {

Aluno::Aluno() : nome(""), matricula(""), curso("") {
    cout << "Construtor de Aluno chamado!" << endl;
}

Aluno::Aluno(string nome, string matricula, string curso)
    : nome(nome), matricula(matricula), curso(curso) {
    cout << "Construtor de Aluno com parâmetros chamado!" << endl;
}

Aluno::~Aluno() {
    cout << "Destruidor de Aluno chamado. Limpeza de recursos!" << endl;
}

void Aluno::exibirInformacoes() {
    cout << "Nome: " << this->nome << endl;
    cout << "Matricula: " << this->matricula << endl;
    cout << "Curso: " << this->curso << endl;
}

// Função amiga para verificar aprovação
void verificarAprovacao(Aluno& aluno, Disciplina& disciplina);
}