#include "disciplina.h"

Disciplina::Disciplina() {
    nome = "";
    cargaHoraria = 0;
    nota = 0.0;
}

Disciplina::Disciplina(std::string nome, int cargaHoraria) {
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->nota = 0.0;
}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() {
    return nota;
}

std::string Disciplina::getNome() {
    return nome;
}
//função amiga
bool verificarAprovacao(const Disciplina& d) {
    return d.nota >= 6.0;
}
