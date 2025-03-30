#include "disciplina.h"
using namespace std;

// constructor
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}
Disciplina::Disciplina(const string& nome, int cargaHoraria, float nota) : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

// configurar e obter nota
void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

// friend function
bool verifiedAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0f;
}