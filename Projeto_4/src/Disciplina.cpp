#include "Disciplina.h"

// Construtor que inicializa os atributos com valores padrão
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0) {}

// Construtor parametrizada que inicializa os atributos com valores fornecidos
Disciplina::Disciplina(const std::string& nome, int cargaHoraria, float nota)
    : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}

// Define a nota da disciplina, validando se está no intervalo [0.0, 10.0]
void Disciplina::setNota(float nota) {
    if (nota >= 0.0 && nota <= 10.0) {
        this->nota = nota;
    }
}

// Retorna o valor da disciplina
float Disciplina::getNota() const {
    return nota;
}

// Retorna o nome da disciplina
std::string Disciplina::getNome() const {
    return nome;
}

// Retorna a carga horaria
int Disciplina::getCargaHoraria() const {
    return cargaHoraria;
}

// Função amiga que verifica se a nota eh suficiente pra passar
bool verificarAprovacao(const Disciplina& disciplina) {
    return disciplina.nota >= 6.0;
}
