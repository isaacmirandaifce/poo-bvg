#include "Aluno.h"
#include <iostream>

Aluno::Aluno(string nome, string id, string curso) : Usuario(nome, id), curso(curso) {}

void Aluno::exibirInformacoes() const {
    Usuario::exibirInformacoes();
    cout << "Curso: " << curso << endl;
}
