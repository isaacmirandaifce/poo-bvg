#include "Disciplina.h"

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(std::string nome, int cargaHoraria) {
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->nota = 0.0f;
}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

void verificarAprovacao(const Disciplina& d) {
    std::cout << "Disciplina: " << d.nome << std::endl;

    if (d.nota >= 6.0) {
        std::cout << "Status: Aprovado" << std::endl;
    } else {
        std::cout << "Status: Reprovado" << std::endl;
    }

    std::cout << "Nota: " << d.nota << std::endl;
    std::cout << "------------------------" << std::endl;
}
