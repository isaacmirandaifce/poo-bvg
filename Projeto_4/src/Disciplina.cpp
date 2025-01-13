#include "Disciplina.h"

/* Construtores */
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

Disciplina::Disciplina(std::string nome, int cargaHoraria)
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0f) {}

Disciplina::Disciplina(std::string nome, int cargaHoraria, float nota)
    : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

/* atribuir uma nota */
void Disciplina::setNota(float nota) {
    this->nota = nota;
}

/* obter a nota */
float Disciplina::getNota() const {
    return nota;
}

/* obter o nome da disciplina */
std::string Disciplina::getNome() const {
    return nome;
}

/* Função amiga para verificar a aprovação */
bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0f;  /* Aprovação com nota >= 6.0 */
}
