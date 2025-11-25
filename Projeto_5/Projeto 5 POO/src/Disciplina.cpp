#include "Disciplina.h"

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(const std::string& nome, int cargaHoraria, float nota)
    : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

void Disciplina::setNota(float n) {
    nota = n;
}

float Disciplina::getNota() const {
    return nota;
}

const std::string& Disciplina::getNome() const {
    return nome;
}

int Disciplina::getCargaHoraria() const {
    return cargaHoraria;
}

bool aprovadoNaDisciplina(const Disciplina& d) {
    return d.nota >= 6.0f;
}
