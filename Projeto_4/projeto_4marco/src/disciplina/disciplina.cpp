#include "Disciplina.h"
#include <iostream>

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(std::string nome, int cargaHoraria)
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0f) {}

void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

void Disciplina::exibirDados() const {
    std::cout << "Disciplina: " << nome << std::endl;
    std::cout << "Carga Horária: " << cargaHoraria << "h" << std::endl;
    std::cout << "Nota: " << nota << std::endl;
}

void verificarAprovacao(const Disciplina& d) {
    std::cout << "Status da disciplina \"" << d.nome << "\": ";
    if (d.nota >= 6.0f)
        std::cout << "Aprovado" << std::endl;
    else
        std::cout << "Reprovado" << std::endl;
}