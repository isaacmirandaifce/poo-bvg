#include "Monitor.h"
#include <iostream>
using namespace std;

Monitor::Monitor() : Usuario(), Aluno(), Professor() {}

Monitor::Monitor(string nome, string email, string tipo, string matricula, string curso, vector<string> disciplinasAluno,
                 string areaDeAtuacao, vector<string> disciplinasMinistradas)
    : Usuario(nome, email, tipo), Aluno(nome, email, tipo, matricula, curso, disciplinasAluno),
      Professor(nome, email, tipo, areaDeAtuacao, disciplinasMinistradas) {}

void Monitor::gerarRelatorio() {
    cout << "=== MONITOR ===" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
    cout << "Disciplinas do Aluno: ";
    for (const string& d : disciplinas) {
        cout << d << " ";
    }
    cout << endl;
    cout << "Area de Atuacao: " << areaDeAtuacao << endl;
    cout << "Disciplinas Ministradas: ";
    for (const string& d : disciplinasMinistradas) {
        cout << d << " ";
    }
    cout << endl << endl;
}