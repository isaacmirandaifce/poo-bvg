#include "Professor.h"
#include <iostream>

using namespace std;

Professor::Professor() {}

Professor::Professor(string nome, string email, string area)
    : Usuario(nome, email, "Professor") {
    areaDeAtuacao = area;
}

void Professor::adicionarDisciplina(string d) {
    disciplinasMinistradas.push_back(d);
}

void Professor::gerarRelatorio() {
    cout << "Professor: " << nome << endl;
    cout << "Area: " << areaDeAtuacao << endl;
}
