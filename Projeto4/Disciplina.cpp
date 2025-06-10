#include <iostream>
#include "Disciplina.h"

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(const std::string& nome, int cargaHoraria) 
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0f) {}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

void Disciplina::exibirInformacoes() const {
    std::cout << "Disciplina: " << nome << std::endl;
    std::cout << "Carga Horaria: " << cargaHoraria << "h" << std::endl;
    std::cout << "Nota: " << nota << std::endl;
}

// Função amiga
bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0f;
}
