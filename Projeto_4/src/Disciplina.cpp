#include "Disciplina.h" 
#include <iostream>  

Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(std::string nome, int cargaHoraria)
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0f) {
}

void Disciplina::setNota(float nota) {
    if (nota >= 0.0f && nota <= 10.0f) { 
        this->nota = nota;
    } else {
        std::cout << "Erro: Nota invalida. Deve estar entre 0 e 10." << std::endl;
    }
}

float Disciplina::getNota() const {
    return nota;
}

bool verificarAprovacao(const Disciplina& disciplina) {
    if (disciplina.nota >= 6.0f) {
        std::cout << "Status em " << disciplina.nome << ": Aprovado (Nota: " << disciplina.nota << ")" << std::endl;
        return true;
    } else {
        std::cout << "Status em " << disciplina.nome << ": Reprovado (Nota: " << disciplina.nota << ")" << std::endl;
        return false;
    }
}