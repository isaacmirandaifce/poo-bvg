#include "Aluno.h"

Aluno::Aluno() : nome("Sem nome"), matricula("N/A"), curso("N/A") {
    cout << "Aluno criado (padrao)." << endl;
}

Aluno::Aluno(const string &nome, const string &matricula, const string &curso)
    : nome(nome), matricula(matricula), curso(curso) {
    cout << "Aluno criado: " << this->nome << endl;
}

Aluno::~Aluno() {
    cout << "Aluno destruido: " << this->nome << endl;
}

void Aluno::exibirInformacoes() const {
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
}

string Aluno::getNome() const { return nome; }
string Aluno::getMatricula() const { return matricula; }
string Aluno::getCurso() const { return curso; }