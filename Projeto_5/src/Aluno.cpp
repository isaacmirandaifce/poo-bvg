#include "Aluno.h"

Aluno::Aluno() : Usuario(), matricula("N/A"), curso("N/A") { tipo = "Aluno"; }

Aluno::Aluno(const string &nome, const string &email, const string &matricula, const string &curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

Aluno::~Aluno() {}

void Aluno::adicionarDisciplina(const string &disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    cout << "---- Relatorio Aluno ----" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << " | Curso: " << curso << endl;
    cout << "Disciplinas: ";
    for (const auto &d : disciplinas) cout << d << " ; ";
    cout << endl;
}

void Aluno::exibirInformacoes() const {
    cout << "Aluno: " << nome << " | Matricula: " << matricula << " | Curso: " << curso << endl;
}

void Aluno::exibirInformacoes(const vector<float> &notas) const {
    cout << "Aluno: " << nome << " - Disciplinas e Notas:" << endl;
    size_t n = disciplinas.size();
    for (size_t i = 0; i < n && i < notas.size(); ++i) {
        cout << "  " << disciplinas[i] << " : " << notas[i] << endl;
    }
}

string Aluno::getMatricula() const { return matricula; }
string Aluno::getCurso() const { return curso; }
const vector<string>& Aluno::getDisciplinas() const { return disciplinas; }