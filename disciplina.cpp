#include "Disciplina.h"

Disciplina::Disciplina() {
    nome = "";
    cargaHoraria = 0;
    nota = 0.0;
}

Disciplina::Disciplina(string n, int c) {
    nome = n;
    cargaHoraria = c;
    nota = 0.0;
}

void Disciplina::setNota(float n) {
    nota = n;
}

float Disciplina::getNota() {
    return nota;
}

string Disciplina::getNome() {
    return nome;
}

bool verificarAprovacao(Disciplina d) {
    return d.nota >= 6.0;
}
