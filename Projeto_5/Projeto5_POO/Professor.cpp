#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(string n, string e, string area) : Usuario(n, e, "Professor") {
    areaDeAtuacao = area;
}

void Professor::adicionarDisciplina(string nome) {
    disciplinasMinistradas.push_back(nome);
}

void Professor::gerarRelatorio() const {
    cout << "Professor: " << nome << " | Área de atuação: " << areaDeAtuacao << endl;
    for (const auto& d : disciplinasMinistradas) {
        cout << " - " << d << endl;
    }
}
