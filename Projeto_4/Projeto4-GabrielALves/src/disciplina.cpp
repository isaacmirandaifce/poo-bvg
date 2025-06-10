#include "Disciplina.h"

// Implementação do construtor padrão
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}

// Implementação do construtor parametrizado
Disciplina::Disciplina(std::string nome, int cargaHoraria)
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0f) {}

// Implementação do método para configurar a nota
void Disciplina::setNota(float n) {
    if (n >= 0.0f && n <= 10.0f) {
        nota = n;
    }
}

// Implementação do método para obter a nota
float Disciplina::getNota() const {
    return nota;
}

// Implementação do método para obter o nome da disciplina
std::string Disciplina::getNome() const {
    return nome;
}