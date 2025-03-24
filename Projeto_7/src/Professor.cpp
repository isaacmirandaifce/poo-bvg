#include "Professor.h"

void Professor::adicionarDisciplina(string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    cout << "Professor: " << nome << " - Area: " << areaAtuacao << " - Disciplinas: ";
    for (const auto& d : disciplinasMinistradas) cout << d << " ";
    cout << endl;
}