#include "../include/Disciplina.h"

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0) {}

Disciplina::Disciplina(const std::string& nome, int cargaHoraria)
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0) {}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0;
}
