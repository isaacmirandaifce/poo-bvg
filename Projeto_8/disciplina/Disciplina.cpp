#include "Disciplina.h"
#include <iostream>

//construtor padrão da classe disciplina
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(std::string nome, int cargaHoraria, float nota) : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

//metodo para definir a nota da disciplina
void Disciplina::setNota(float nota) {
    this->nota = nota;
}

//metodo para obter a nora da disciplina
float Disciplina::getNota() const {
    return nota;
}

bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.getNota() >= 7.0;
}
