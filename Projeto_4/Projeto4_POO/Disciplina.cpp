#include "Disciplina.h"
#include <iostream>
using namespace std;

Disciplina::Disciplina() {}

Disciplina::Disciplina(string n, int ch) {
    nome = n;
    cargaHoraria = ch;
}

void Disciplina::setNota(float n) {
    nota = n;
}

float Disciplina::getNota() const {
    return nota;
}

void verificarAprovacao(const Disciplina& d) {
    cout << "Disciplina: " << d.nome << " - Nota: " << d.nota;
    if (d.nota >= 6.0)
        cout << " -> Aprovado\n";
    else
        cout << " -> Reprovado\n";
}
