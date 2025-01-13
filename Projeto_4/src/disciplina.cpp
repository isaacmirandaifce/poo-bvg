#include "../include/disciplina.h"
#include <iostream>

Disciplina::Disciplina(std::string nome, int ch, float nota)
:nome(nome), cargaHoraria(ch), nota(nota){}

Disciplina::~Disciplina() {}

// Método para exibir informações da disciplina
void Disciplina::exibirInformacoes() const {
    std::cout << "Disciplina: " << nome << "\nCarga Horaria: " << cargaHoraria  << "\nNota: " << nota << std::endl;
}
// Setter e Getter
void Disciplina::setNota(float nota) {
    this->nota = nota;
}

float Disciplina::getNota() const {
    return nota;
}

// Função amiga para verificar aprovação
bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0;
}