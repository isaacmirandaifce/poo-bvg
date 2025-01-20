#include "Disciplina.h"
#include <iostream>
#include "Aluno.h"

namespace std {

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {
    cout << "Construtor de Disciplina chamado!" << endl;
}

Disciplina::Disciplina(string nome, int cargaHoraria)
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0f) {
    cout << "Construtor de Disciplina com parâmetros chamado!" << endl;
}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() {
    return this->nota;
}

// Função amiga para verificar aprovação
void verificarAprovacao(Aluno& aluno, Disciplina& disciplina) {
    if (disciplina.getNota() >= 6.0f) {
        cout << aluno.getNome() << " foi aprovado na disciplina " << disciplina.nome << "!" << endl;
    } else {
        cout << aluno.getNome() << " foi reprovado na disciplina " << disciplina.nome << "." << endl;
    }
}
}