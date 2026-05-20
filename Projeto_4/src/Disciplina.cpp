#include "Disciplina.h"

// Construtor padrão
Disciplina::Disciplina() {
    nome = "";
    cargaHoraria = 0;
    nota = 0.0f;
}

// Construtor parametrizado
Disciplina::Disciplina(std::string nome, int cargaHoraria, float nota) {
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->nota = nota;
}

// Setter da nota
void Disciplina::setNota(float nota) {
    this->nota = nota;
}

// Getter da nota
float Disciplina::getNota() const {
    return nota;
}

// Getter do nome
std::string Disciplina::getNome() const {
    return nome;
}

// Getter da carga horária
int Disciplina::getCargaHoraria() const {
    return cargaHoraria;
}

// Função amiga: acessa o atributo privado 'nota' diretamente
// para verificar se o aluno foi aprovado (nota >= 6.0)
bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0f;
}
