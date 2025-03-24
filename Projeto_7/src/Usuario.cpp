#include "Usuario.h"

Usuario::~Usuario() 

// UsuarioAutenticavel.cpp
#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::~UsuarioAutenticavel() {}

// Aluno.cpp
#include "Aluno.h"

void Aluno::gerarRelatorio() const {
    cout << "Aluno: " << nome << " - Matricula: " << matricula << " - Curso: " << curso << endl;
}

bool Aluno::autenticar(string s) const {
    return senha == s;
}
