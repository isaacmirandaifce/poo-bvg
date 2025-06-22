#include "Disciplina.h"

Disciplina::Disciplina() {}

Disciplina::Disciplina(string n, int ch) {
    nome = n;
    cargaHoraria = ch;
    nota = 0;
}

void Disciplina::setNota(float n) {
    nota = n;
}

float Disciplina::getNota() const {
    return nota;
}

string Disciplina::getNome() const {
    return nome;
}
