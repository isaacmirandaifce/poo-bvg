#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor() : Usuario(), areaDeAtuacao(""), disciplinasMinistradas({}) {}

Professor::Professor(string nome, string email, string tipo, string areaDeAtuacao, vector<string> disciplinasMinistradas)
    : Usuario(nome, email, tipo), areaDeAtuacao(areaDeAtuacao), disciplinasMinistradas(disciplinasMinistradas) {}

void Professor::gerarRelatorio() {
    cout << "=== PROFESSOR ===" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Area de Atuacao: " << areaDeAtuacao << endl;
    cout << "Disciplinas Ministradas: ";
    for (const string& d : disciplinasMinistradas) {
        cout << d << " ";
    }
    cout << endl << endl;
}

string Professor::getAreaDeAtuacao() {
    return areaDeAtuacao;
}