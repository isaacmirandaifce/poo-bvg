#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno() {}

Aluno::Aluno(string n, string e, string m, string c) : Usuario(n, e, "Aluno") {
    matricula = m;
    curso = c;
}

void Aluno::adicionarDisciplina(const Disciplina& d) {
    disciplinas.push_back(d);
}

void Aluno::gerarRelatorio() const {
    cout << "Aluno: " << nome << " | Matrícula: " << matricula << " | Curso: " << curso << endl;
    for (const auto& d : disciplinas) {
        cout << " - " << d.getNome() << endl;
    }
}

void Aluno::gerarRelatorio(bool comNota) const {
    cout << "Aluno: " << nome << " | Matrícula: " << matricula << " | Curso: " << curso << endl;
    for (const auto& d : disciplinas) {
        cout << " - " << d.getNome();
        if (comNota)
            cout << " | Nota: " << d.getNota();
        cout << endl;
    }
}
