#include "Disciplina.h"
#include <iostream>

// Construtor padrão
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

// Construtor parametrizado
Disciplina::Disciplina(std::string nome, int cargaHoraria, float nota) 
    : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

// Métodos para notas
void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

// Getters
std::string Disciplina::getNome() const { return nome; }
int Disciplina::getCargaHoraria() const { return cargaHoraria; }

// Implementação da função amiga
bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0f;
}