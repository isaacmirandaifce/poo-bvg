#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno(const string& nome, const string& email, const string& matricula, const string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::gerarRelatorio() const {
    cout << "Aluno: " << nome << "\nMatrícula: " << matricula << "\nCurso: " << curso << endl;
}

void Aluno::gerarRelatorio(const vector<float>& notas) const {
    gerarRelatorio(); // Chama a versão padrão
    cout << "Notas: ";
    for (float nota : notas) {
        cout << nota << " ";
    }
    cout << endl;
}
