#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(const string& nome, const string& email, const string& areaDeAtuacao, const vector<string>& disciplinas)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao), disciplinasMinistradas(disciplinas) {}

void Professor::gerarRelatorio() const {
    cout << "Professor: " << nome << "\nÁrea de Atuação: " << areaDeAtuacao << "\nDisciplinas Ministradas: ";
    for (const string& disciplina : disciplinasMinistradas) {
        cout << disciplina << " ";
    }
    cout << endl;
}
