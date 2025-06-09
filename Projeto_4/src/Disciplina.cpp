#include "Disciplina.h"

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0) {}

Disciplina::Disciplina(std::string nome, int cargaHoraria, float nota)
    : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

void Disciplina::setNota(float n) {
    nota = n;
}

float Disciplina::getNota() const {
    return nota;
}

std::string Disciplina::getNome() const {
    return nome;
}

bool verificarAprovacao(const Disciplina& d) {
    return d.nota >= 6.0;
}
