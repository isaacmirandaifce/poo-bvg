#include "Disciplina.h"

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0) {}

Disciplina::Disciplina(string n, int ch, float nt) : nome(n), cargaHoraria(ch), nota(nt) {}

void Disciplina::setNota(float nt) {
    nota = nt;
}

float Disciplina::getNota() const {
    return nota;
}

string Disciplina::getNome() const {
    return nome;
}

bool verificarAprovacao(const Disciplina& d) {
    return d.nota >= 6.0;
}
