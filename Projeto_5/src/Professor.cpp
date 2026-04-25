#include "Professor.h"
#include <iostream>

using namespace std;

Professor::Professor(){}

Professor::Professor(string nome, string email, string area)
: Usuario(nome, email, "Professor") {
    areaDeAtuacao = area;
}

void Professor::adicionarDisciplina(string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    cout << "Professor: " << nome << endl;
    cout << "Area: " << areaDeAtuacao << endl;

}