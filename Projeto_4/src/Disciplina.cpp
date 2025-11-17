#include "../include/Disciplina.h"

Disciplina::Disciplina() {
    nome = "";
    cargaHoraria = 0;
    nota = 0.0f;
}

Disciplina::Disciplina(std::string nome, int cargaHoraria){
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->nota = 0.0f;
}

void Disciplina::setNota(float nota){
    this->nota = nota;
}

float Disciplina::getNota(){
    return nota;
}

bool verificarAprovacao(const Disciplina& d){
    return d.nota >= 6.0f;
}