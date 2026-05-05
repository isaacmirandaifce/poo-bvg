#include "Disciplina.h"
#include <iostream>

using namespace std;

Disciplina::Disciplina() {
    nome = "";
    cargaHoraria = 0;
    nota = 0.0;
}

Disciplina::Disciplina(string nome, int cargaHoraria) {
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->nota = 0.0;
}

void Disciplina::setNota(float nota) {
    if (nota >= 0 && nota <= 10) {
        this->nota = nota;
    } else {
        this->nota = 0.0;
        cout << "Nota invalida. Atribuido valor 0." << endl;
    }
}

float Disciplina::getNota() {
    return this->nota;
}

string Disciplina::getNome() {
    return this->nome;
}

// Implementação da função amiga
// Acessa diretamente o atributo privado 'nota' do objeto Disciplina
bool verificarAprovacao(const Disciplina &d) {
    return d.nota >= 6.0;
}
