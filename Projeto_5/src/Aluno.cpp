#include <iostream>
#include "Aluno.h"

using namespace std;

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(string nome, string email, string matricula, string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
}

void Aluno::adicionarNota(double nota) {
    notas.push_back(nota);
}

void Aluno::gerarRelatorio() const {
    cout << "[Relatorio de Aluno]" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
    cout << "Disciplinas cursadas: ";
    if (disciplinasCursadas.empty()) {
        cout << "nenhuma";
    }
    for (size_t i = 0; i < disciplinasCursadas.size(); ++i) {
        cout << disciplinasCursadas[i];
        if (i != disciplinasCursadas.size() - 1) cout << ", ";
    }
    cout << endl;
}

void Aluno::exibirInformacoes() const {
    cout << "Aluno: " << nome << " | Matricula: " << matricula << " | Curso: " << curso << endl;
}

void Aluno::exibirInformacoes(bool comNotas) const {
    exibirInformacoes();
    if (comNotas) {
        cout << "Notas: ";
        if (notas.empty()) {
            cout << "sem notas lancadas";
        }
        for (size_t i = 0; i < notas.size(); ++i) {
            cout << notas[i];
            if (i != notas.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}
