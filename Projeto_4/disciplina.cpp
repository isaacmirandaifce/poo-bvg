#include "Disciplina.h"
#include <iostream>

//construtor padrão
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(std::string nome, int cargaHoraria, float nota)
    : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

//definindo nota na diciplina
void Disciplina::setNota(float nota) {
    this->nota = nota;
}

//obtendo nota
float Disciplina::getNota() const {
    return nota;
}

//verificando aprovação
bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0;
}
