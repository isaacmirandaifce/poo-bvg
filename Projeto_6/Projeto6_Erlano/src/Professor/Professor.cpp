#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor() : UsuarioAutenticavel(), areaDeAtuacao(""), disciplinasMinistradas({}), tipoUsuario(TipoUsuario::PROFESSOR) {}

Professor::Professor(string nome, string email, string tipo, string senha, string areaDeAtuacao, vector<string> disciplinasMinistradas)
    : UsuarioAutenticavel(nome, email, tipo, senha), areaDeAtuacao(areaDeAtuacao), disciplinasMinistradas(disciplinasMinistradas), tipoUsuario(TipoUsuario::PROFESSOR) {}

void Professor::gerarRelatorio() {
    cout << "=== RELATORIO DE PROFESSOR ===" << endl;
    cout << "Nome: " << nome << ", Email: " << email << ", Tipo: " << tipo << endl;
    cout << "Área: " << areaDeAtuacao << ", Disciplinas: ";
    for (auto d : disciplinasMinistradas) cout << d << " ";
    cout << endl << endl;
}

bool Professor::autenticar(string senhaTentativa) {
    return senhaTentativa == senha;
}