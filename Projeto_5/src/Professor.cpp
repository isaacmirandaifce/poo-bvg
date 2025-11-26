#include "Professor.h"

Professor::Professor() : Usuario(), areaDeAtuacao("N/A") { tipo = "Professor"; }

Professor::Professor(const string &nome, const string &email, const string &area)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area) {}

Professor::~Professor() {}

void Professor::adicionarDisciplina(const string &disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    cout << "---- Relatorio Professor ----" << endl;
    cout << "Nome: " << nome << " | Area: " << areaDeAtuacao << endl;
    cout << "Ministra: ";
    for (auto &d : disciplinasMinistradas) cout << d << " ; ";
    cout << endl;
}

const vector<string>& Professor::getDisciplinasMinistradas() const { return disciplinasMinistradas; }
string Professor::getArea() const { return areaDeAtuacao; }