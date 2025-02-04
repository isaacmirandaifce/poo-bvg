#include "disciplina.h"

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(string nome, int cargaHoraria, float nota) : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

bool verificarAprovacao(const Disciplina &disciplina) {
    return disciplina.nota >= 6.0f;
}
