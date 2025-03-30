#include "Disciplina.h"

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(const std::string& nome, int cargaHoraria, float nota)
    : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

std::string Disciplina::getNome() const {
    return nome;
}

bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0f;
}
