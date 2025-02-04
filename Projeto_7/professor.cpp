#include "professor.h"
#include <iostream>

Professor::Professor(string nome, string id, string disciplina) : Usuario(nome, id), disciplina(disciplina) {}

void Professor::exibirInformacoes() const {
    Usuario::exibirInformacoes();
    cout << "Disciplina: " << disciplina << endl;
}
