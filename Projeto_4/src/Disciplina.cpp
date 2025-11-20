#include "Disciplina.h"
#include "Aluno.h" 

// ↑ apenas para permitir que o tipo Aluno seja conhecido na impl da funcao amiga

Disciplina::Disciplina() : nome("Sem nome"), cargaHoraria(0), nota(0.0f) {
    cout << "Disciplina criada (padrao)." << endl;
}

Disciplina::Disciplina(const string &nome, int cargaHoraria)
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0f) {
    cout << "Disciplina criada: " << this->nome << endl;
}

Disciplina::~Disciplina() {
    cout << "Disciplina destruida: " << nome << endl;
}

void Disciplina::setNota(float n) {
    this->nota = n;
}

float Disciplina::getNota() const {
    return nota;
}

string Disciplina::getNome() const {
    return nome;
}

int Disciplina::getCargaHoraria() const {
    return cargaHoraria;
}

// Implementacao da funcao amiga

bool verificarAprovacao(const Aluno &aluno, const Disciplina &disc) {
    
// Acessa disc.nota diretamente
    
(void)aluno; 
    return disc.nota >= 6.0f;
}

// ↑  aqui a função aluno não é necessário para o critério de nota, mas incluído para seguir requisito