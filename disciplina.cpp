#include "Disciplina.h"

Disciplina::Disciplina() {
    nome = "";
    cargaHoraria = 0;
    nota = 0;
}

Disciplina::Disciplina(string nome, int cargaHoraria, float nota) {
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->nota = nota;
}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() {
    return nota;
}

bool verificarAprovacao(Disciplina d) {
    return d.nota >= 6.0;
}
