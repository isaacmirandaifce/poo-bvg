#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(const string& nome, const string& email, const string& senha,
                     const string& areaDeAtuacao, const vector<string>& disciplinas)
    : UsuarioAutenticavel(nome, email, senha, TipoUsuario::PROFESSOR), // Passa TipoUsuario::PROFESSOR
      areaDeAtuacao(areaDeAtuacao), disciplinasMinistradas(disciplinas) {}

bool Professor::autenticar(const string& senha) const {
    return this->senha == senha;
}

void Professor::gerarRelatorio() const {
    cout << "Professor: " << nome << "\nEmail: " << email << "\nÁrea de Atuação: " 
         << areaDeAtuacao << "\nDisciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        cout << " - " << disciplina << "\n";
    }
}
