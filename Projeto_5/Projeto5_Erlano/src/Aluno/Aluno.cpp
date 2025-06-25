#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno() : Usuario(), matricula(""), curso(""), disciplinas({}) {}

Aluno::Aluno(string nome, string email, string tipo, string matricula, string curso, vector<string> disciplinas)
    : Usuario(nome, email, tipo), matricula(matricula), curso(curso), disciplinas(disciplinas) {}

void Aluno::gerarRelatorio() {
    cout << "=== ALUNO ===" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
    cout << "Disciplinas: ";
    for (const string& d : disciplinas) {
        cout << d << " ";
    }
    cout << endl << endl;
}

void Aluno::gerarRelatorio(bool exibirNotas) {
    gerarRelatorio();
    if (exibirNotas) {
        cout << "Notas: 10, 9" << endl;
    }
}