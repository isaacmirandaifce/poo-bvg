#include <iostream>
#include "Professor.h"

using namespace std;

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(string nome, string email, string areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

void Professor::adicionarDisciplinaMinistrada(const string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    cout << "[Relatorio de Professor]" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Area de atuacao: " << areaDeAtuacao << endl;
    cout << "Disciplinas ministradas: ";
    if (disciplinasMinistradas.empty()) {
        cout << "nenhuma";
    }
    for (size_t i = 0; i < disciplinasMinistradas.size(); ++i) {
        cout << disciplinasMinistradas[i];
        if (i != disciplinasMinistradas.size() - 1) cout << ", ";
    }
    cout << endl;
}
