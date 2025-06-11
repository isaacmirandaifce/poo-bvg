#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor() {}

Professor::Professor(string nome, string email, string disciplina, string titulacao)
    : Usuario(nome, email), disciplina(disciplina), titulacao(titulacao) {}

string Professor::getDisciplina() const {
    return disciplina;
}

string Professor::getTitulacao() const {
    return titulacao;
}

void Professor::gerarRelatorio() const {
    cout << "Professor: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Disciplina: " << disciplina << endl;
    cout << "Titulação: " << titulacao << endl;
}
