#include "Professor.h"
#include <iostream>

using namespace std;

Professor::Professor(string nome, string email, string senha, string departamento)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha), departamento(departamento) {}

bool Professor::autenticar(string senhaDigitada) {
    return this->senha == senhaDigitada;
}

void Professor::gerarRelatorio() const {
    cout << "=== Relatorio de Professor ===" << endl;
    cout << "Docente: " << nome << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Email Institucional: " << email << endl;
    cout << "============================" << endl;
}
