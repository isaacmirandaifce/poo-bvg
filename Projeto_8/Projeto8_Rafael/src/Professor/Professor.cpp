#include "Professor.h"
#include <iostream>
#include <algorithm>
using namespace std;

Professor::Professor() : UsuarioAutenticavel(), areaDeAtuacao(""), disciplinasMinistradas({}), tipoUsuario(TipoUsuario::PROFESSOR) {}

Professor::Professor(string nome, string email, string tipo, string senha, string areaDeAtuacao, vector<string> disciplinasMinistradas)
    : Usuario(nome, email, tipo),  // <- ADICIONE ESSA LINHA
      UsuarioAutenticavel(nome, email, tipo, senha),
      areaDeAtuacao(areaDeAtuacao),
      disciplinasMinistradas(disciplinasMinistradas),
      tipoUsuario(TipoUsuario::PROFESSOR) {}

void Professor::gerarRelatorio() const {
    cout << "=== RELATORIO DE PROFESSOR ===" << endl;
    cout << "Nome: " << nome << ", Email: " << email << ", Tipo: " << tipo << endl;
    cout << "Área: " << areaDeAtuacao << ", Disciplinas: ";
    for (const auto& d : disciplinasMinistradas) cout << d << " ";
    cout << endl << endl;
}

bool Professor::autenticar(string senhaTentativa) {
    return senhaTentativa == senha;
}

// Métodos para filtragem
string Professor::getNome() const {
    return nome;
}

string Professor::getAreaDeAtuacao() const {
    return areaDeAtuacao;
}

vector<string> Professor::getDisciplinasMinistradas() const {
    return disciplinasMinistradas;
}

bool Professor::ministraDisciplina(const string& disciplina) const {
    return find(disciplinasMinistradas.begin(), disciplinasMinistradas.end(), disciplina) != disciplinasMinistradas.end();
}

string Professor::getEmail() const {
    return email;
}
